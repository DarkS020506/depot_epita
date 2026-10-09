def retirer_indices(liste: list[any], indices: set[int]) -> int:
    count=0
    for i in indices:
        i=i-count
        if i<len(liste):
            liste.pop(i)
            count+=1
    return count
