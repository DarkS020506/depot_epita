def triangle(hauteur:int, est_creux:bool =True, orientation: int=0) -> str: 
    if orientation==0:
        caract=1
        espace_vide=0
    elif orientation==1:
        caract=1
        espace_vide=hauteur-1
    else:
        caract=hauteur
        espace_vide=0
    ligne=""
    for i in range(hauteur):
        if caract!=hauteur and caract!=2 and caract!=1 and est_creux==True:
            ligne_X=str("X"+(" "*(caract-2))+"X")
        else:
            ligne_X="X"*caract
        ligne+=str(" "*espace_vide)
        ligne+=ligne_X
        if i!=hauteur-1:
            ligne+="\n"
        if orientation==0:
            caract+=1
        elif orientation==1:
            caract+=+1
            espace_vide-=1
        else:
            caract-=1
            espace_vide+=1
    return ligne


def decrire_forme(forme: str):
    lignes = forme.split("\n")
    hauteur = len(lignes)
    largeurs = list(map(len, lignes))
    if hauteur == 0 or any(l == 0 for l in largeurs):
        return None
    if largeurs == list(range(1, hauteur + 1)):
        largeur = hauteur
        char = lignes[-1][0]
        est_creuse = False
        if hauteur >= 3:
            est_creuse = True
            for i in range(1, hauteur - 1):
                if lignes[i][0] != char or lignes[i][-1] != char:
                    est_creuse = False
                if any(c != " " for c in lignes[i][1:-1]):
                    est_creuse = False

        return ("triangle", (hauteur, largeur), est_creuse)
    if len(set(largeurs)) != 1:
        return None
    largeur = largeurs[0]
    char = lignes[0][0]
    est_creuse = False
    if hauteur >= 3 and largeur >= 3:
        est_creuse = True
        for i in range(1, hauteur - 1):
            if lignes[i][0] != char or lignes[i][-1] != char:
                est_creuse = False
            interieur = lignes[i][1:-1]
            if any(c != " " for c in interieur):
                est_creuse = False
    if hauteur == largeur:
        return ("carre", (hauteur, largeur), est_creuse)
    else:
        return ("rectangle", (hauteur, largeur), est_creuse)

