entier=int(input("entier"))
nombre=0
for i in range(50):
    entier=int(entier/10)
    nombre=nombre+1
    if entier==0:
        print(nombre)
        break
