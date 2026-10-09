-- Projet BdD et SQL — Base Aéroport  Sylvain BOZONNIER, Adam ABID, Sam CHARTOUNI, Matthieu CAZAUX 
-- Groupe Bravo

CREATE DATABASE IF NOT EXISTS proj_bravo;
USE proj_bravo;

CREATE TABLE IF NOT EXISTS Aeroports (
  id_aeroport   INT           AUTO_INCREMENT PRIMARY KEY,
  code_iata     CHAR(3)       NOT NULL UNIQUE,
  nom           VARCHAR(100)  NOT NULL,
  ville         VARCHAR(100)  NOT NULL,
  pays          VARCHAR(100)  NOT NULL
);

CREATE TABLE IF NOT EXISTS Terminaux (
  id_terminal   INT           AUTO_INCREMENT PRIMARY KEY,
  nom_terminal  VARCHAR(10)   NOT NULL,
  id_aeroport   INT           NOT NULL,
  FOREIGN KEY (id_aeroport) REFERENCES Aeroports(id_aeroport)
);

CREATE TABLE IF NOT EXISTS Avions (
  id_avion      INT           AUTO_INCREMENT PRIMARY KEY,
  modele        VARCHAR(50)   NOT NULL,
  capacite      INT           NOT NULL,
  compagnie     VARCHAR(100)  NOT NULL
);

CREATE TABLE IF NOT EXISTS Vols (
  id_vol        INT           AUTO_INCREMENT PRIMARY KEY,
  numero_vol    VARCHAR(10)   NOT NULL UNIQUE,
  depart        DATETIME      NOT NULL,
  arrivee       DATETIME      NOT NULL,
  id_avion      INT           NOT NULL,
  id_terminal   INT           NOT NULL,
  FOREIGN KEY (id_avion)    REFERENCES Avions(id_avion),
  FOREIGN KEY (id_terminal) REFERENCES Terminaux(id_terminal)
);

CREATE TABLE IF NOT EXISTS Passagers (
  id_passager   INT           AUTO_INCREMENT PRIMARY KEY,
  nom           VARCHAR(100)  NOT NULL,
  prenom        VARCHAR(100)  NOT NULL,
  email         VARCHAR(150)  UNIQUE,
  passeport     VARCHAR(20)   NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS Billets (
  id_billet     INT           AUTO_INCREMENT PRIMARY KEY,
  classe        VARCHAR(20)   NOT NULL,
  prix          DECIMAL(8,2)  NOT NULL,
  siege         VARCHAR(5),
  id_passager   INT           NOT NULL,
  id_vol        INT           NOT NULL,
  FOREIGN KEY (id_passager) REFERENCES Passagers(id_passager),
  FOREIGN KEY (id_vol)      REFERENCES Vols(id_vol)
);

CREATE TABLE IF NOT EXISTS Bagages (
  id_bagage     INT           AUTO_INCREMENT PRIMARY KEY,
  poids_kg      DECIMAL(5,2)  NOT NULL,
  statut        VARCHAR(30)   DEFAULT 'enregistre',
  id_billet     INT           NOT NULL,
  FOREIGN KEY (id_billet) REFERENCES Billets(id_billet)
);


INSERT INTO Aeroports (code_iata, nom, ville, pays) VALUES
  ('CDG', 'Charles de Gaulle', 'Paris',   'France'),
  ('LHR', 'Heathrow',          'Londres', 'Royaume-Uni'),
  ('MAD', 'Barajas',           'Madrid',  'Espagne');

INSERT INTO Terminaux (nom_terminal, id_aeroport) VALUES
  ('T2E', 1),
  ('T1',  1),
  ('T5',  2);

INSERT INTO Avions (modele, capacite, compagnie) VALUES
  ('Airbus A320',  180, 'Air France'),
  ('Boeing 777',   300, 'British Airways'),
  ('Airbus A380',  500, 'Air France');

INSERT INTO Vols (numero_vol, depart, arrivee, id_avion, id_terminal) VALUES
  ('AF1234', '2025-06-01 08:00:00', '2025-06-01 10:00:00', 1, 1),
  ('BA5678', '2025-06-02 14:00:00', '2025-06-02 15:45:00', 2, 3),
  ('AF9999', '2025-06-03 07:30:00', '2025-06-03 09:00:00', 3, 2);

INSERT INTO Passagers (nom, prenom, email, passeport) VALUES
  ('Dupont', 'Alice', 'alice@mail.com', 'FR123456'),
  ('Martin', 'Bob',   'bob@mail.com',   'FR789012'),
  ('Garcia', 'Clara', 'clara@mail.com', 'ES456789');

INSERT INTO Billets (classe, prix, siege, id_passager, id_vol) VALUES
  ('Economie', 150.00, '12A', 1, 1),
  ('Business', 450.00, '3C',  2, 2),
  ('Economie', 200.00, '22B', 3, 3);

INSERT INTO Bagages (poids_kg, statut, id_billet) VALUES
  (23.0, 'enregistre', 1),
  (18.5, 'embarque',   2),
  (20.0, 'enregistre', 3);


CREATE OR REPLACE VIEW vue_billets_detail AS
  SELECT
    b.id_billet,
    p.nom        AS passager_nom,
    p.prenom     AS passager_prenom,
    v.numero_vol,
    v.depart,
    v.arrivee,
    b.classe,
    b.prix,
    b.siege
  FROM Billets b
  JOIN Passagers p ON b.id_passager = p.id_passager
  JOIN Vols      v ON b.id_vol      = v.id_vol;

CREATE OR REPLACE VIEW vue_bagages_securite AS
  SELECT id_bagage, poids_kg, statut, id_billet
  FROM Bagages;

INSERT INTO vue_bagages_securite (poids_kg, statut, id_billet)
  VALUES (15.0, 'enregistre', 1);

UPDATE vue_bagages_securite
  SET   statut = 'livre'
  WHERE id_bagage = 1;

DELETE FROM vue_bagages_securite
  WHERE id_bagage = 4;

DROP USER IF EXISTS 'utilisateur_standard'@'localhost';

CREATE USER 'utilisateur_standard'@'localhost' IDENTIFIED BY 'motdepasse123';

GRANT SELECT ON proj_bravo.* TO 'utilisateur_standard'@'localhost';

GRANT INSERT, UPDATE, DELETE ON proj_bravo.Bagages TO 'utilisateur_standard'@'localhost';

