def arrangements(ensemble: set[any], p: int) -> list[list[any]]:
    if p == 0:
        return [[]]
    resultat = []
    for elem in ensemble:
        for suite in arrangements(ensemble-{elem}, p-1):
            resultat.append([elem]+suite)

    return resultat
