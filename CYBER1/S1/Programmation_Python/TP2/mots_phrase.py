chaine=str(input("Entrer la chaine: "))
phrase=""
espace_trouvé=False
for i in range(len(chaine)):
    if chaine[i] == " ":
        if i+1<len (chaine):
            
            if chaine[i+1] != " ":
                phrase=phrase+","
                continue
            else:
                continue
        else:
            continue
    else:
        phrase=phrase+chaine[i]
print(phrase)

