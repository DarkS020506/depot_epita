import os
import sys
import importlib
from datetime import datetime

FICHIER_NOTE = 'note.txt'
FICHIER_JOURNAL = 'journal.txt'

def CABexercice() -> str:
    return sys.argv[1]

def CABimporter(nom_module: str, nom_fonction: str = ''):
    #module = importlib.import_module(module)
    spec = importlib.util.spec_from_file_location(nom_module, f"{nom_module}.py")
    module = importlib.util.module_from_spec(spec)
    sys.modules[module] = module
    spec.loader.exec_module(module)
    if not nom_fonction: 
        return module
    return getattr(module, nom_fonction)

def CABinitier(*fichiers : str) -> None:
    # détuire et recréer le répertoire de test
    repertoire = f".{CABexercice()}"
    os.system(f"(rm -fr  {repertoire}; mkdir {repertoire}) 2>/dev/null")

    # y copier les fichiers de travail spécifiés
    os.system(f"cp -fp {" ".join(fichiers)} {repertoire}")

    # descendre dans le repertoire pour toute la suite du test
    os.chdir(repertoire)

    # A COMPLETER : vérifier la présence de l'exercice
    pass

def CABterminer(erreur: str = "", statut: int = 0) -> None:
    if not erreur:
        note = CABnoter(0, "%")
        statut = 0 if note == "100%" else 1
    else:
        note = CABnoter(0, erreur)

    print(f"{CABexercice()} : {note}") 
    sys.exit(statut)

def CABverifier(points: int, description: str, verification: str, messageNOK: str = "")  -> None:
    # faire la vérification
    est_ok = eval(verification)

    # déterminer le statut du test
    statut = "OK " if est_ok else "NOK"

    # déterminer la variation de note et noter
    if points == int(points):
        points = int(points)
    if est_ok == (points >= 0):
        CABnoter(points)
        variation = f" {points:+02d} " if type(points) is int else f" {points:+.1f} "
    else:
        variation = f"({points:+02d})" if type(points) is int else f"({points:+.1f})"

    # établir la conclusion
    conclusion = "OK" if est_ok else "NOK" + messageNOK
    
    # journaliser, sauf si test à points négatifs réussi (pour ne pas surcharger le journal)
    if not (est_ok and points <= 0):
        CABjournaliser(f"{statut} {variation} {description} {conclusion}")

def CABnoter(delta: float = 0, action: str = "") -> str|int:

    # lit la note du fichier s'il existe, le crée avec 0 sinon
    try:
        with open(FICHIER_NOTE, "r") as fichier:
            note = float(fichier.readline())        
    except FileNotFoundError:
        with open(FICHIER_NOTE, "w") as fichier:
            fichier.write("0")
        note = 0

    # si l'action est % final
    if action == "%":
        # ajuster la note et conclure
        note = int(note)
        if note < 0:
            note = 0
        elif note >= 99:
            note = 100
        note = f"{note}%" 
    # si l'action est un message
    elif action:
        # le mettre en guise de note
        note="${action}"
    # sinon ajouter le delta
    else:
        note += delta

    # mettre à jour le fichier note et retourner la note
    with open(FICHIER_NOTE, "w") as fichier:
        fichier.write(f"{note}")
    return note

def CABjournaliser(message: str) -> None:
    heure = datetime.now().strftime("%H:%M:%S")
    with open(FICHIER_JOURNAL, "a") as fichier:
        fichier.write(f"{heure} {message}\n")

