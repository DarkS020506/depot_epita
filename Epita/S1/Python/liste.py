
def append(liste: dict[int, any], value: any) -> None:
    liste[len(liste)+1]=value
    return liste

def count(liste: dict[int, any], value: any) -> int:
    nb=0
    for cle in liste:
        if liste[cle]==value:
            nb+=1
    return nb

def index(liste: dict[int, any], value: any, \
start: int = 0, stop: int = 9223372036854775807) -> int:
    for cle in liste:
            if liste[cle]==value:
                return cle
    return -1

def insert(liste: dict[int, any], index: int, value: any) -> None:
    liste[index]=value
    return liste

def pop(liste: dict[int, any], index: int) -> any:
    nv_liste={}
    temp=0
    for cle in liste:
        if cle==index:
            temp+=1
            continue
        else:
            nv_liste[cle]=liste[cle]
    if temp==0:
        return None
    else:
        return nv_liste

def remove(liste: dict[int, any], value: any) -> None:
    nv_liste={}
    temp=0
    for cle in liste:
        if liste[cle]==value:
            temp+=1
            continue
        else:
            nv_liste[cle]=liste[cle]
    if temp==0:
        return None
    else:
        return nv_liste

def reverse(liste: dict[int, any]) -> None:
    nv_liste = {}
    for cle in sorted(liste.keys(), reverse=True):
        nv_liste[cle] = liste[cle]
    return nv_liste
