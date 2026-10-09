chaine=input("Entrer une chaine: ")
voyelle="aeiouyAEIOUY"
i=0
somme=0
for caractère in chaine[i:]:
    for caract in voyelle:
        if caractère==caract:
            somme=somme+1
    i=i+1
print(somme)
