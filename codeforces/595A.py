n, m = map(int, input().split())

ans = 0
for i in range(n):
    A = list(map(int, input().split()))
    for j in range(0, len(A), 2):
        if A[j] == 1 or A[j+1] == 1:
            ans += 1
print(ans)

