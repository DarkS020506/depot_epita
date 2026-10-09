try:
    hauteur=float(input(""))
    largeur=float(input(""))
    if hauteur>0 and largeur>0:
        surface=hauteur*largeur
        print(surface)
    else:
        print("erreur")
except ValueError:
    print("erreur")
