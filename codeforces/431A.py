A = list(map(int, input().split()))
s = list(map(int, list(input())))
ans = 0
for a in s:
    ans += A[a-1]

print(ans)
