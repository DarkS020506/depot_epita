def triangle_pascal(ordre: int) -> list[list[int]]:
    liste=[]
    for i in range(ordre+1):
        ligne=[]
        for y in range(i+1):
            if y==0 or y==i:
                ligne.append(1)
            else:
                ligne.append(liste[i-1][y-1]+liste[i-1][y])
        liste.append(ligne)
    return liste

