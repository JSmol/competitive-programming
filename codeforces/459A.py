a,b,c,d = map(int, input().split())

if a == c:
    x = abs(b-d)
    print(a+x, b, c+x, d)
elif b == d:
    x = abs(a-c)
    print(a, b+x, c, d+x)
else:
    x = abs(a-c)
    y = abs(b-d)
    if x == y:
        if a < c and b < d:
            print(a+x,b, a, b+x)
        if a < c and b > d:
            print(a+x,b, a, b-x)
        if a > c and b > d:
            print(a-x,b, a, b-x)
        if a > c and b < d:
            print(a-x,b, a, b+x)
    else:
        print(-1)

