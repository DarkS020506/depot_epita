x=float(input("x:"))
n=int(input("n:"))
if n<0:
    print("erreur")
elif n==0:
    print(1.0)
else:
    produit=1
    for i in range(n):
        produit=produit*x
    print(produit)
