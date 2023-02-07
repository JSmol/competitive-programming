n, k = map(int, input().split())
ans, p = 0, 0

for _ in range(k):
  a = int(input())
  ans += (a - p) * ((n+1) - a)
  p = a

print(ans)