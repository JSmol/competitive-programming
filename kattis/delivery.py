n, k = map(int, input().split())
A = [tuple(map(int, input().split())) for i in range(n)]
A.sort()

r = 0
ans = 0
for a in A:
  if a[0] > 0:
    break

  ans += (abs(a[0]) * ((a[1] - r) // k)) * 2
  r = (a[1] - r) % k

  if r:
    ans += (abs(a[0])) * 2
    r = k - r

r = 0
for a in reversed(A):
  if a[0] <= 0:
    break

  ans += (abs(a[0]) * ((a[1] - r) // k)) * 2
  r = (a[1] - r) % k

  if r:
    ans += (abs(a[0])) * 2
    r = k - r

print(ans)