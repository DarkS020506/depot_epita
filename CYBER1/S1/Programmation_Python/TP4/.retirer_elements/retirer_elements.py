def retirer_elements(liste: list[any], elements: set[any]) -> dict[any, int]:
    if len(elements)==0:
        return {}
    else:
        count=0
        dico={}
        for i in elements:
            dico[i]=0
            for y in range(len(liste)-1):
                y=y-count
                if liste[y-1]==i:
                    liste.pop(y)
                    dico[i]+=1  
        return dico
