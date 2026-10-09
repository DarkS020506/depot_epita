chaine=input("Entrer une chaine: ")
caract=str(input("Entrer un caractère: "))
occurence=0
valide=0

if caract<str("A") or (caract>str("Z") and caract<str("a")) or caract>str("z"):
    
    valide=1

if valide==0:
    for caractère in chaine:
        if caractère==caract:
            occurence+=1
    print(occurence)
else:
    print("erreur")
