chaine=input("Entrer une chaine: ")
value=True
chaine_sans_espace=""
for c in chaine:
    if c!=" ":
        chaine_sans_espace+=c
print(chaine_sans_espace)
if chaine=="":
    value=True
else:
    for i in range(len(chaine_sans_espace)):
        caractere=chaine_sans_espace[i]
        nv_caractere=caractere.lower()
        caractere_inverse=chaine_sans_espace[len(chaine_sans_espace)-i-1]
        nv_caractere_inverse=caractere_inverse.lower()
        if nv_caractere != nv_caractere_inverse:
            print(i)
            value=False
            break

print(value)
