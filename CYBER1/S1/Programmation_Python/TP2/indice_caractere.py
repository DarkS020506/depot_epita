chaine=input("")
caract=str(input(""))
valide=0
if len(caract)>1:
    print("erreur")
else:
    if caract<str("A") or (caract>str("Z") and caract<str("a")) or caract>str("z"):
        valide=1

    if valide==0:

        i=0
        y=i+1
        value=1
        for caractère in chaine[i+1:]:
            if caract==caractère:
                print(y)
                value=0
                break
            y=y+1
        i=i+1
        if value==1:
            print(-1)
    else:
        print("erreur")
