def append(liste: dict[int, any], value: any) -> None:
    if len(liste) == 0:
        new_index = 0
    else:
        new_index = max(liste.keys()) + 1
    liste[new_index] = value

def count(liste: dict[int, any], value: any) -> int:
    return sum(1 for v in liste.values() if v == value)

def index(liste: dict[int, any], value: any, start: int = 0, stop: int = 9223372036854775807) -> int:
    for index, val in liste.items():
        if start <= index <= stop and val == value:
            return index
    return -1

def insert(liste: dict[int, any], index: int, value: any) -> None:
    if index < 0 or index in liste:
        return
    for i in range(max(liste.keys()), index - 1, -1):
        liste[i + 1] = liste[i]
    liste[index] = value

def pop(liste: dict[int, any], index: int) -> any:
    if index in liste:
        value = liste.pop(index)
        # Décalage des éléments suivants
        for i in range(index + 1, max(liste.keys()) + 1):
            liste[i - 1] = liste[i]
        liste.pop(max(liste.keys()))
        return value
    return None

def remove(liste: dict[int, any], value: any) -> None:
    for index, val in liste.items():
        if val == value:
            liste.pop(index)
            # Décalage des éléments suivants
            for i in range(index + 1, max(liste.keys()) + 1):
                liste[i - 1] = liste[i]
            liste.pop(max(liste.keys()))
            break

def reverse(liste: dict[int, any]) -> None:
    reversed_items = list(liste.values())[::-1]
    for i, value in enumerate(reversed_items):
        liste[i] = value
