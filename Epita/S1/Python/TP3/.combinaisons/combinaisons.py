def combinaisons(n:int,p:int)->int:
    if p<0 or n<0 or p>n:
        return -1
    if p==0 or p==n:
        return 1
    if n<0 or p<0 or p>n:
        return 0
    return combinaisons(n-1,p-1) + combinaisons(n-1,p)

print(combinaisons(5,3))
