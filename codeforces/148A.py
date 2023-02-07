a,b,c,d,e = map(int, [input() for i in range(5)])

ans = 0
for i in range(1, e+1):
    if i % a == 0:
        ans+=1

    elif i % b == 0:
        ans+=1

    elif i % c == 0:
        ans+=1

    elif i % d == 0:
        ans+=1
print(ans)
