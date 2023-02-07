n = int(input())
A = list(map(int, input().split()))
m = max(A)
ans = 0
for a in A:
    ans += m - a

print(ans)
