while True:
    entier=float(input("valeur"))
    try:
        if float(-5)<=entier<=float(5):
            print(entier)
            break
        else:
            print("erreur")
            break
    except ValueError:
        print("erreur")
