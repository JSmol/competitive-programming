n, x = map(int,input().split())
m = x
s = 0
for i in range(n):
    c, d = input().split()
    d = int(d)
    if c == '+':
        m += d
    elif c == '-' and m >= d:
        m -= d
    elif c == '-' and m < d:
        s += 1

print(m, s)
