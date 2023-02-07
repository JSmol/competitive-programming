n, l, a = map(int, input().split())

A = [tuple(map(int, input().split())) for _ in range(n)]

if len(A) < 1:
    print(l // a)
    exit()

ans = A[0][0] // a
p = A[0][0] + A[0][1]
for i in range(1, n):
    ans += (A[i][0] - p) // a
    p = A[i][0] + A[i][1]

ans += (l - p) // a

print(ans)
