a, b = map(int, input().split())

if a < b:
    if 2*a < b:
        print(a)
    else:
        print((a+b)//3)
else:
    if 2*b < a:
        print(b)
    else:
        print((a+b)//3)
