def est_premier(entier):
    if type(entier)!=int or entier<=0:
        return None
    for i in range(2,entier):
        print(i)
        if(entier%i==0):
            return False
        else:
            continue
    return True

def factorielle(entier):
    if type(entier)!=int or entier<=0:
        return -1
    puissance=1
    for i in range(1,entier+1):
        puissance=puissance*i
    return(puissance)

def min(liste):
    if not isinstance(liste, list) or len(liste)==0:
        return -1.0
    for caractere in liste:
        if not isinstance(caractere, float) or caractere<0:
            return -1.0
    min=liste[0]
    for caractere in liste:
        if caractere<min:
            min=caractere
    return min

def contient_pairs(liste):
    for caractere in liste:
        if caractere%2==0:
            return True
    return False

def trier(liste):
    for i in range(len(liste)):
        nbr=liste[i]
        for y in range(i+1,len(liste)):
            if nbr>=liste[y]:
                liste[i],liste[y]=liste[y],liste[i]
    return liste
0
def est_palindrome(liste,debut,fin):
    value=0
    for i in range(debut,fin):
        if liste[i]!=liste[fin-i-1]:
            value+=1
    if value!=0:
        return False
    else:
        return True
    
def inserer(liste,index,valeur):
    liste1=liste[:index]
    liste2=liste[index:]
    liste1.append(valeur)
    for caractere in liste2:
        liste1.append(caractere)
    return liste1
def extraire(liste,debut,fin):
    if debut>fin or debut<0 or debut>len(liste) or fin<0 or fin>len(liste):
        return None
    liste_e=liste[debut:fin]
    return liste_e
def retirer_negatifs(liste):
    liste_e=[]
    nbr=0
    for i in range(len(liste)):
        if liste[i]>0:
            liste_e.append(liste[i])
        else:
            nbr+=1
    return liste_e, nbr

def somme(matriceA,matriceB):
    if len(matriceA)!=len(matriceB):
        return None,1
    for i in range(len(matriceA)):
        if len(matriceA[i])!=len(matriceB[i]):
            print(1)
            return None,2
    somme_tot=[]
    for i in range(len(matriceA)):
        somme=[]
        for y in range(len(matriceA[i])):
            somme_tempo=matriceA[i][y]+matriceB[i][y]
            somme.append(somme_tempo)
        somme_tot.append(somme)
    return somme_tot
        
def sous_ensembles(ensemble):
    sous_ensembles=[]
    sous_ensembles.append([])
    for i in range(len(ensemble)):
        sous_ensembles.append([ensemble[i]])
    for i in range(len(ensemble)):
        for y in range(i+1,len(ensemble)):
            sous_ensembles.append([ensemble[i],ensemble[y]])
    sous_ensembles.append(ensemble)
    return sous_ensembles
def sous_ensembles2(ensemble):
    sous_ens = [[]]
    for element in ensemble:
        for sous_ensemble in sous_ens:
            sous_ens=sous_ens+[sous_ensemble+[element]]
    return sous_ens
#print(est_premier(3.2))
#print(factorielle(6))
#print(min([1.3, 0.7, 3.14]))
#print(contient_pairs([-2, 7, 3]))
#print(trier([1.3, -0.7, -3.14]))
#print(est_palindrome("kayak", 0, len("kayak")))
#print(inserer([1.3, -3.14], 1, -0.7))
#print(extraire([1, 2, 3, 4, 5], 1, 3))
##print(retirer_negatifs([1.3, -0.7, -3.14]))
#print(somme([ [0, 1], [1, 0], [1, 2] ], [ [1, 2], [3, 4], [5, 6] ]))
print(sous_ensembles2(['A', 'B', 'C','D']))