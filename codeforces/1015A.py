n, m = map(int, input().split())

A = [1]*m
for i in range(n):
    l, r = map(int, input().split())
    l-=1
    r-=1
    for j in range(l, r+1):
        A[j] = 0

S = set()
for i in range(m):
    if A[i] == 1:
        S.add(i+1)

print(len(S))
print(*S)

