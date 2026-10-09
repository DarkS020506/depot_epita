def ajouter(ensemble: dict, element: any) -> int:
    if element in ensemble:
        ensemble[element] += 1
    else:
        ensemble[element] = 1
    return ensemble[element]


def retirer(ensemble: dict, element: any) -> int:
    if element in ensemble:
        ensemble[element] -= 1
        if ensemble[element] == 0:
            del ensemble[element]  
        return ensemble.get(element, 0)
    return -1


def union(ensemble1: dict, ensemble2: dict) -> dict:
    union_ensemble = ensemble1.copy()
    for element, multiplicite in ensemble2.items():
        if element in union_ensemble:
            union_ensemble[element] += multiplicite
        else:
            union_ensemble[element] = multiplicite
    
    return union_ensemble
