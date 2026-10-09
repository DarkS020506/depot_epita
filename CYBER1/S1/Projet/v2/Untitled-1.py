import random
import string
import os

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

def nettoyer_cle(cle):
    cle_propre = ""
    for char in cle:
        if char.isalpha():
            cle_propre += char.lower()
    return cle_propre

def adapter_cle(message_clair, message_cle):
    cle_adaptee = ""
    j = 0
    for i in range(len(message_clair)):
        if not message_clair[i].isalpha():
            cle_adaptee += " "
        else:
            cle_adaptee += message_cle[j % len(message_cle)]
            j += 1
    return cle_adaptee

def encodage_vigenere(message_clair, message_cle):
    message_vignere=""
    table=table_vigenere()
    for i in range(len(message_clair)):
        lettre=message_clair[i]
        cle=message_cle[i]
        if lettre==" " or not lettre.isalpha():
            message_vignere=message_vignere+lettre
        else:
            colone=ord(lettre.lower())-97
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
        if lettre==" " or not lettre.isalpha():
            message_clair=message_clair+lettre
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

def encoder_plusieurs_messages(message_cle_base):
    print("\n--- Mode multi-messages avec la même clé ---")
    print(f"Clé de base utilisée : {message_cle_base}")
    nb_messages = int(input("Combien de messages voulez-vous encoder ? "))
    
    resultats = []
    for i in range(nb_messages):
        print(f"\nMessage {i+1}/{nb_messages}")
        message_clair = str(input("Entrer le message à encoder : "))
        message_cle = adapter_cle(message_clair, message_cle_base)
        message_vignere = encodage_vigenere(message_clair, message_cle)
        
        resultats.append({
            'clair': message_clair,
            'cle': message_cle,
            'vigenere': message_vignere
        })
        
        print(f"Message encodé : {message_vignere}")
    
    enregistrer = int(input("\nVoulez-vous enregistrer tous les résultats (resultat.txt) ? 0 (oui) / 1 (non) : "))
    if enregistrer == 0:
        with open("resultat.txt", "w", encoding="utf-8") as fichier:
            fichier.write(f"CLÉ DE BASE : {message_cle_base}\n\n")
            for i, res in enumerate(resultats):
                fichier.write(f"Message {i+1}:\n")
                fichier.write(f"message clair : {res['clair']}\n")
                fichier.write(f"message clé adaptée : {res['cle']}\n")
                fichier.write(f"message vigenere : {res['vigenere']}\n\n")
        print("Tous les messages ont été sauvegardés dans resultat.txt")
    
    return resultats

def encoder_fichier():
    fichier_entree = input("nom du fichier (ex: fichier.txt)  : ")
    fichier_sortie = input("nom du fichier de sortie (ex: fichier_sortie.txt) : ")

    try:
        with open(fichier_entree, 'r', encoding='utf-8') as fichier:
            contenu_fichier = fichier.read()
    except FileNotFoundError:
        print("fichier not found.")
        return

    message_cle_base = str(input("cle du message : "))
    message_cle_base = nettoyer_cle(message_cle_base)
    message_cle = adapter_cle(contenu_fichier, message_cle_base)

    message_vignere = encodage_vigenere(contenu_fichier, message_cle)

    with open(fichier_sortie, 'w', encoding='utf-8') as fichier_sortie:
        fichier_sortie.write(message_vignere)

    print(f"fichier sauvegarder ici :  '{fichier_sortie.name}'.")

def bienvenue():
    clear()
    titre("SYSTÈME DE CHIFFREMENT VIGENÈRE ")
    print("Bienvenue dans le programme.\n")
    print("  1 → Générer une clé automatiquement")
    print("  2 → Entrer votre propre clé")
    print()
    choix = int(question("Choisissez une option (1-2) : "))
    if choix == 1:
        message_cle_base = generer_cle()
    else:
        message_cle_input = input("Entrer la clé du message : ")
        message_cle_base = nettoyer_cle(message_cle_input)
    clear()
    titre("CLÉ SÉLECTIONNÉE")
    print("Clé utilisée :", message_cle_base, "\n")
    print("  1 → Encoder plusieurs messages (batch)")
    print("  2 → Encoder / Décoder un seul message\n")
    multi = int(question("Votre choix : "))
    if multi == 1:
        encoder_plusieurs_messages(message_cle_base)
        return 0
    clear()
    titre("ENCODAGE / DÉCODAGE")
    message_clair = input("Entrer le message à encoder/décoder : ")
    message_cle = adapter_cle(message_clair, message_cle_base)
    print("\n  1 → Encoder")
    print("  2 → Décoder\n")
    action = int(question("Votre choix : "))
    if action == 1:
        message_vignere = encodage_vigenere(message_clair, message_cle)
    else:
        message_vignere = decoder_vigenere(message_clair, message_cle)
    print("\nRésultat :\n")
    print("message clair   :", message_clair)
    print("message clé     :", message_cle)
    print("message vigenere:", message_vignere)
    print("\nVoulez-vous enregistrer le résultat ?")
    print("  1 → Oui")
    print("  2 → Non\n")
    enregistrer = int(question("Votre choix : "))
    if enregistrer == 1:
        sauvegarder(message_clair, message_cle, message_vignere)
        print("\n✔ Résultat sauvegardé dans resultat.txt")
    Vig_fin()
    return 0
def clear():
    if os.name=="nt":
        os.system("cls")
    else:
        os.system("clear")
def titre(text):
    print("┌" + "─" * 59 + "┐")
    print("│                            CODE VIGENERE                             │")
    print("└" + "─" * 59 + "┘\n")
def question(text):
    print(text)
    return input("> ")
def Vig_fin():
    input("\nMerci d'avoir utilisé le programme veuillez appuyer sur entrée pour mettre fin à celui-ci")
encoder_fichier()
#bienvenue()