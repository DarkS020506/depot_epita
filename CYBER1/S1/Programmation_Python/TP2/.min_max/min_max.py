chaine=input("")
if chaine=="":
    print("vide")
else:
    min=chaine[0]
    max=chaine[0]
    for caractère in chaine:
        if caractère>max:
            max=caractère
        if caractère<min:
            min=caractère
    print(min,max)
