def generer_liste(n):
    liste=[]
    for i in range(2,n+1):
        liste.append(i)
    return liste
def eratosthène(n):
    liste=generer_liste(n)
    i=0
    while i<len(liste):
        if i<len(liste):
            y=i+1
            while y<len(liste):
                if liste[y]%liste[i]==0:
                    liste.pop(y)
                else:
                    y+=1
        i+=1
    return liste

print(eratosthène(100))