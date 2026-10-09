entier=int(input("entier:"))
if entier==0:
    print("erreur")
if entier==1:
    print(False)
else:
    est_premier=True
    for i in range(2,entier-1):
        if entier%i==0:
            est_premier=False
            break
    print(est_premier)
