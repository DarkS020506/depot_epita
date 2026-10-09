a=float(input("a:"))
b=float(input("b:"))
c=float(input("c:"))
if a>=b and a>=c:
    print(a)
elif b>=c and b>=a:
    print(b)
else:
    print(c)
