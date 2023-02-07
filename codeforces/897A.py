n, m = map(int, input().split())
s = list(input())
for i in range(m):
    l, r, c, d = input().split()
    for j in range(int(l)-1, int(r)):
        if s[j] == c:
            s[j] = d

print(*s, sep="")
