a,b,c = map(int, input().split())
x = min([a//3,b//2,c//2])
a -= x * 3
b -= x * 2
c -= x * 2
s = (a,b,c)

x *= 7
ans = x
for o in range(7):
    y = x
    a,b,c=s
    for j in range(7):
        i = (j+o) % 7
        if i == 0 or i == 3 or i == 6:
            if a == 0:
                break
            a -= 1
        if i == 1 or i == 5:
            if b == 0:
                break
            b -= 1
        if i == 2 or i == 4:
            if c == 0:
                break
            c -= 1
        y += 1
    ans = max(ans, y)
print(ans)
