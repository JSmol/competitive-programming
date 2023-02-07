n, m = map(int, input().split())

A = [list(input()) for i in range(n)]
ans = 1

for i in range(m):
  c = True
  for j in range(n):
    if A[j][i] != '_':
      c = False
  if c:
    ans += 1

print(ans)
