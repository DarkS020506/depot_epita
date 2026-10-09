def diviseur(n):
    liste=[]
    for i in range(-n,0,1):
        if n%i==0:
            liste.append(i)
    for i in range(1,n+1,1):
        if n%i==0:
            liste.append(i)
    return liste

print(diviseur(21))