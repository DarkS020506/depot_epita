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
        if i!=hauteur -1:
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

print(triangle(5))

