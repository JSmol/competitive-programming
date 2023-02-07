n = int(input())
A = list(map(int, input().split()))
S = [0] * n
T = [0] * n
t = sum(A)
s = 0
for i, a in enumerate(A):
    s += a
    S[i] = s
    T[i] = t
    t -= a

ans = 0
j = n-1
for i in range(n):
    while i < j and S[i] > T[j]:
        j-=1
    if i < j and S[i] == T[j]:
        ans = max(ans, S[i])
print(ans)
