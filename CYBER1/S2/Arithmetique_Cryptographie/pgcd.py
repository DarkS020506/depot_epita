def pgcd(a,b):
    q=a
    if a>=b:
        q=b
    while q > 0:
        if a%q==0 and b%q==0:
            return q
        q=q-1
    return 1
print(pgcd(12,3))