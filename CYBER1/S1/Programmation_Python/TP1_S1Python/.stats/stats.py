nombre=[]
while True:
    try:
        valeur=float(input(""))
        if valeur ==0:
            break
        nombre.append(valeur)
    except ValueError:
        print("erreur")
if len(nombre)==0:
    print("vide")
else:
    plus_petit=min(nombre)
    plus_grande=max(nombre)
    moyenne=sum(nombre)/len(nombre)
    print(plus_petit,moyenne,plus_grande)
