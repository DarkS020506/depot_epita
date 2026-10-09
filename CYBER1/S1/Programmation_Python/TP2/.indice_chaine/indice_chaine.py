chaine1=str(input("Entrer la chaine 1: "))
chaine2=str(input("Etrer la chaine 2: "))
taille1=len(chaine1)
taille2=len(chaine2)
indice=-1
for i in range(taille1-taille2+1):
    value=True
    for y in range(taille2):
        if chaine1[i+y]!=chaine2[y]:
            value=False
            break
    if value==True:
        indice=i
        break

print(indice)

