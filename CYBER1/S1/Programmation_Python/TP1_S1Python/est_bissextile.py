annee=int(input("donner une annee: "))
if annee%4==0 and annee%100==0 and annee%400==0:
    print("True")
else:
    print("False")
