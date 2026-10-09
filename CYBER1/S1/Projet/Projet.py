import random
import string

def table_vigenere():
    alphabet=string.ascii_uppercase
    taille=len(alphabet)
    table=[]
    for i in range(taille):
        ligne=alphabet[i:]+alphabet[:i]
        table.append(ligne)
    return table

def generer_cle():
    taille=int(input("Entrer la taille de la clé générée : "))
    nouvelle_cle=""
    for i in range(taille):
        lettre_aleatoire=random.choice(string.ascii_lowercase)
        nouvelle_cle=nouvelle_cle+lettre_aleatoire
    return nouvelle_cle


def adapter_cle(message_clair, message_cle):
    if len(message_cle)==len(message_clair):
        return message_cle
    if len(message_cle)<len(message_clair):
        repet=(message_cle*((len(message_clair)//len(message_cle))+1))[:len(message_clair)]
        return repet
    return message_cle[:len(message_clair)]

def encodage_vigenere(message_clair, message_cle):
    message_vignere=""
    table=table_vigenere()
    for i in range(len(message_clair)):
        lettre=message_clair[i]
        cle=message_cle[i]
        if lettre==" ":
            message_vignere=message_vignere+" "
        else:
            colone=ord(lettre)-97
            lignes=ord(cle)-97
            majuscule=table[lignes][colone]
            code_minuscule=ord(majuscule)+32
            nouvelle_lettre=chr(code_minuscule)
            message_vignere=message_vignere+nouvelle_lettre
    return message_vignere


def decoder_vigenere(message_vignere, message_cle):
    message_clair=""
    table=table_vigenere()
    for i in range(len(message_vignere)):
        lettre=message_vignere[i]
        cle=message_cle[i]
        if lettre==" ":
            message_clair=message_clair+" "
        else:
            ligne=ord(cle)-97
            ligne_table=table[ligne]
            code_maj=ord(lettre)-32
            lettre_maj=chr(code_maj)
            col=ligne_table.index(lettre_maj)
            nouvelle_lettre=chr(col+97)
            message_clair=message_clair+nouvelle_lettre
    return message_clair


def sauvegarder(message_clair, message_cle, message_vignere):
    with open("resultat.txt", "w", encoding="utf-8") as fichier:
        fichier.write("message clair : ")
        fichier.write(message_clair)
        fichier.write("\n")
        fichier.write("message clé : ")
        fichier.write(message_cle)
        fichier.write("\n")
        fichier.write("message vigenere : ")
        fichier.write(message_vignere)

def bienvenue():
    choix = int(input("Bienvenue dans le projet de Vigenère, voulez-vous générer une clé ? 0 (oui) / 1 (non) : "))
    message_clair = str(input("Entrer le message à encoder/décoder : "))
    if choix == 0:
        message_cle = generer_cle()
        message_cle = adapter_cle(message_clair, message_cle)
    else:
        message_cle = str(input("Entrer la clé du message : "))
        message_cle = adapter_cle(message_clair, message_cle)
    action = int(input("Voulez-vous encoder (0) ou décoder (1) ? "))
    if action == 0:
        message_vignere = encodage_vigenere(message_clair, message_cle)
    else:
        message_vignere = decoder_vigenere(message_clair, message_cle)
    enregistrer = int(input("Voulez-vous enregistrer le résultat ? 0 (oui) / 1 (non) : "))
    if enregistrer == 0:
        sauvegarder(message_clair, message_cle, message_vignere)
    print("message clair : ", message_clair)
    print("message clé  : ", message_cle)
    print("message vigenere : ", message_vignere)
    return 0
bienvenue()
