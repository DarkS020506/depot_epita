chaine=input("Entrer une chaine: ")
repète=0
alphabet="abcdefghijklmnopqrstuvwxyz"
value=False
i=0
for caractère in chaine:

    for caract in chaine[i+1:]:
        if caractère==caract:
            value=True
    i+=1
print(value)
        
