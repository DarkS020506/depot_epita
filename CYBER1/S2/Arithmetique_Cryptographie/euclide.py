def euclide(a,b):
    r=a%b
    while r!=0:
        a=b
        b=r
        r=a%b
    return b

def euclide_recursif(a,b):
    if a%b==0:
        return b
    else:
        euclide_recursif(b,a%b)
    

print("euclide: ", euclide(735,126))