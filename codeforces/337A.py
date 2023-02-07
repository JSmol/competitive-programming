n, m = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = 1<<30
for i in range(0, m-n+1):
    ans = min(ans, A[i+n-1] - A[i])

print(ans)
