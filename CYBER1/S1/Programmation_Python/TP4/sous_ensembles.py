def sous_ensembles(ensemble: set[any]) -> list[set[any]]:
    elements=list(ensemble)
    liste_sous_ensembles=[set()]
    for element_e in elements:
        taille_initiale=len(liste_sous_ensembles)
        for i in range(taille_initiale):
            p=liste_sous_ensembles[i]
            p_prime=p.union({element_e})
            liste_sous_ensembles.insert(i+taille_initiale,p_prime)
    return liste_sous_ensembles
