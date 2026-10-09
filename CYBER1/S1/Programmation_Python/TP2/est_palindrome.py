chaine=input("Entrer une chaine: ")
i=0
value=True
taille=len(chaine)
if chaine=="":
    value=True
else:
    for caractère in chaine[i:]:
        if caractère!=chaine[taille-i-1]:
            value=False
            i=i+1
    
        else:
            i=i+1
print(value)
