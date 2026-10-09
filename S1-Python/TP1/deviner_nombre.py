import random
entier_aleatoire=random.randint(1,10)
max_tentatives=3
for i in range(1,max_tentatives+1):
    try:
        devine=int(input(""))
        if devine==entier_aleatoire:
            print("gagné")
            break
        elif i<max_tentatives:
            if devine<entier_aleatoire:
                   print("plus grand")
            else:
                   print("plus petit")
        else:
            print("perdu",entier_aleatoire)
    except ValueError:
        print("erreur")
        break

