-- use corrige_velib ;

-- 1) création des tables

-- table des vélos
CREATE TABLE velos (
  IDvelo INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  Numero INT NOT NULL UNIQUE,
  MiseEnService DATE NOT NULL,
  Electrique BOOLEAN
) ;

-- tables des modes d'authentification
-- cette table ne contiendra que quatre lignes et ne sera mise à jour 
--  que très exceptionnellement, 
-- un code de deux caractères sera plus simple et suffisant
-- (mais bien sûr un numéro automatique sera tout à fait correct)
CREATE TABLE types_auth (
  CodeAuth VARCHAR(2) PRIMARY KEY, 
  TypeAuth VARCHAR(20) NOT NULL
) ;

INSERT INTO types_auth (CodeAuth, TypeAuth) VALUES ('ID', 'Identifiant à 6 chiffres et code secret') ; 
INSERT INTO types_auth (CodeAuth, TypeAuth) VALUES ('NV', 'Navigo') ; 
INSERT INTO types_auth (CodeAuth, TypeAuth) VALUES ('CV', 'Carte Vélib''') ; 
INSERT INTO types_auth (CodeAuth, TypeAuth) VALUES ('SP', 'Smartphone') ; 

-- table des abonnés
CREATE TABLE abonnes (
  IDabonne INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  Nom VARCHAR(100) NOT NULL,
  Prenom VARCHAR(100) NOT NULL,
  DateNaissance DATE NOT NULL,
  Email VARCHAR(255),
  CodeAuth VARCHAR(2) NOT NULL,
  Identifiant VARCHAR(11) NOT NULL, 
  CodeSecret INT,
  CONSTRAINT FK_abo_auth FOREIGN KEY (CodeAuth) REFERENCES types_auth (CodeAuth),
  CONSTRAINT UK_abo UNIQUE (Nom, Prenom, DateNaissance)
) ;

-- table des stations
-- variantes : séparer CodeZone et NumeroStation n'est pas obligatoire, 
-- mais c'est préférable pour l'atomicité
-- l'ID automatique n'est pas obligatoire, 
-- mais les clefs artificielles sont préférables aux clefs naturelles
CREATE TABLE stations (
  IDstation INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  CodeZone INT NOT NULL,
  NumeroStation INT NOT NULL,
  Nom VARCHAR(100) NOT NULL,
  NbPlaces INT NOT NULL,
  CONSTRAINT UK_sta_num UNIQUE (CodeZone, NumeroStation),
  CONSTRAINT UK_sta_nom UNIQUE (CodeZone, Nom)
) ;

-- table des trajets
CREATE TABLE trajets (
  IDtrajet INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  IDabonne INT NOT NULL,
  IDvelo INT NOT NULL,
  DateHeureDepart DATETIME NOT NULL,
  IDstationDepart INT NOT NULL,
  DateHeureRetour DATETIME NULL, -- tant que le trajet est en cours, on ignore la date/heure de retour...
  IDstationArrivee INT NULL, -- ... et la station d'arrivée
  CONSTRAINT FK_trj_abo FOREIGN KEY (IDabonne) REFERENCES abonnes (IDabonne),
  CONSTRAINT FK_trj_velo FOREIGN KEY (IDvelo) REFERENCES velos (IDvelo),
  CONSTRAINT FK_trj_sta_dep FOREIGN KEY (IDstationDepart) REFERENCES stations (IDstation),
  CONSTRAINT FK_trj_sta_arr FOREIGN KEY (IDstationArrivee) REFERENCES stations (IDstation)
) ;


-- 2) import des données
-- recherche de doublon sur la table source
select COUNT(*) as nb_lignes, 
	COUNT(identifiant_station) as nb_lignes_avec_ID, 
    COUNT(DISTINCT identifiant_station) as nb_ID_distinctes
FROM _velib._stations ; -- 1472
 
-- import des stations, avec élimination du doublon
-- et séparation entre CodeZone (milliers) 
-- et et Numerostation (trois derniers chiffres)
INSERT INTO stations (CodeZone, NumeroStation, Nom, NbPlaces)
SELECT FLOOR(Identifiant_station / 1000),
  MOD(Identifiant_station, 1000),
  Nom_station,
  MAX(nombre_places_station) -- MIN serait tout aussi correct
FROM _velib._stations
GROUP BY FLOOR(Identifiant_station / 1000),
  MOD(Identifiant_station, 1000),
  Nom_station ; 

-- vérification des doublons de client
SELECT COUNT(*),  
	COUNT(email), -- pour vérifier qu'ils ont tous un email
    COUNT(DISTINCT email) -- nombre sans doublon
FROM _velib._clients ;

-- import des données avec conversion des DateNaissance en date
-- et détection du type d'authentification
INSERT INTO abonnes (Nom, Prenom, DateNaissance, Email, Identifiant, CodeSecret, CodeAuth)
SELECT DISTINCT nom, prenom, STR_TO_DATE(DateNaissance, '%Y/%m/%d'), email, 
	COALESCE(identifiant, id_navigo, id_carte, id_telephone),
    Code_Secret,
    CASE WHEN identifiant IS NOT NULL AND code_secret IS NOT NULL THEN 'ID'
      WHEN id_navigo IS NOT NULL THEN 'NV'
      WHEN id_carte IS NOT NULL THEN 'CV'
      WHEN id_telephone IS NOT NULL THEN 'SP'
	END 
FROM _velib._clients ; 

-- insertion des vélos test (données imaginaires pour les colonnes Mise en service et Électrique
INSERT INTO velos (Numero, MiseEnService, Electrique) VALUES (25874, '2020-01-01', 0) ; -- ID obtenue : 1
INSERT INTO velos (Numero, MiseEnService, Electrique) VALUES (38855, '2020-01-01', 0) ; -- ID obtenue : 2
INSERT INTO velos (Numero, MiseEnService, Electrique) VALUES (31456, '2020-01-01', 0) ; -- ID obtenue : 3
select * from velos ; 


-- recherche des ID des deux abonnés test
SELECT * FROM abonnes WHERE nom IN ('Leboeuf', 'Chauvert') ; 
-- Simon = 51, Yoshi = 41

-- recherche des ID des deux stations test
SELECT * FROM stations WHERE CodeZone * 1000 + NumeroStation IN (13002, 13017) ; 
-- 13017 = 914, 13002 = 1002

-- insertion des trajets
INSERT INTO trajets (IDabonne, IDvelo, DateHeureDepart, IDstationDepart, DateHeureRetour, IDstationArrivee) 
VALUES (51, 1, '2025-04-18 11:25',  1002, '2025-04-18 11:57', 914) ; 
INSERT INTO trajets (IDabonne, IDvelo, DateHeureDepart, IDstationDepart, DateHeureRetour, IDstationArrivee) 
VALUES (41, 2, '2025-04-18 14:05',  1002, NULL, NULL) ; 
INSERT INTO trajets (IDabonne, IDvelo, DateHeureDepart, IDstationDepart, DateHeureRetour, IDstationArrivee) 
VALUES (51, 3, '2025-04-18 12:33', 914,  '2025-04-18 13:45', 1002) ; 

-- test de différentes fonctions sur la date et l'heure actuelles
-- (CURDATE et CURRENT_TIME sont insuffisantes, les autres sont OK)
SELECT CURDATE(), NOW(), SYSDATE(), CURRENT_TIME(), CURRENT_TIMESTAMP() ;

-- vue sur les vélos non rendus
CREATE OR REPLACE VIEW v_encours AS
SELECT V.Numero AS numero_velo,
	T.IDtrajet AS numero_trajet,
    TIMESTAMPDIFF(MINUTE, T.DateHeureDepart, CURRENT_TIMESTAMP) as duree_trajet,
    A.Nom, A.Prenom, A.DateNaissance AS date_naissance,
    SD.CodeZone * 1000 + SD.NumeroStation AS numero_station_depart,
    SD.Nom AS nom_station_depart
FROM trajets AS T
  INNER JOIN velos AS V ON T.IDvelo = V.IDvelo
  INNER JOIN abonnes AS A ON T.IDabonne = A.IDabonne
  INNER JOIN stations AS SD ON T.IDstationDepart = SD.IDstation
WHERE IDstationArrivee IS NULL ; 

-- vue statistique
CREATE OR REPLACE VIEW v_stats_abo AS
SELECT A.Nom, A.Prenom, 
	COUNT(*) AS nb_trajets,
    SUM(TIMESTAMPDIFF(MINUTE, T.DateHeureDepart, T.DateHeureRetour)) AS duree_totale,
    SUM(CASE WHEN TIMESTAMPDIFF(MINUTE, T.DateHeureDepart, T.DateHeureRetour) > 60 THEN 1 END) AS nb_trajets_longs
FROM trajets AS T
  INNER JOIN velos AS V ON T.IDvelo = V.IDvelo
  INNER JOIN abonnes AS A ON T.IDabonne = A.IDabonne
  INNER JOIN stations AS SD ON T.IDstationDepart = SD.IDstation
WHERE IDstationArrivee IS NOT NULL 
GROUP BY A.Nom, A.Prenom ; 


