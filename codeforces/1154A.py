A = list(map(int, input().split()))
m = max(A)
ans = []
for a in A:
    if a < m:
        ans.append(m-a)

print(*sorted(ans))
