def retirer_doublons(liste: list[any], en_place: bool = True) -> list[any]:
    vus=set()
    resultat=[]
    for element in liste:
        if element not in vus:
            vus.add(element)
            resultat.append(element)
    if en_place:
        liste.clear()
        liste.extend(resultat)
        return liste
    else:
        return resultat
