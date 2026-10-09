chaine=input("Entrer une chaine: ")
N=int(input("Entrer un entier positif: "))
M=int(input("Entrer un entier supérieur: "))
chaine_vide=""
i=0
for caractère in chaine[i:]:
    if i%M==(N%M):
        chaine_vide=chaine_vide+caractère
    i=i+1
print(chaine_vide[::-1])
