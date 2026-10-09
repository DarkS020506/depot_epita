def remplacer_chaine(s1:str,s2:str,s3:str)->str:
    nouveau=""
    i=0
    while i<len(s1):
        if s1[i:i+len(s2)]==s2:
            nouveau+=s3
            i+=len(s2)
        else:
            nouveau+=s1[i]
            i+=1
    return nouveau

print(remplacer_chaine('haaaaa !','aa','o'))


