q, m, s, l = map(int, input().split())

ans = 0
ans += (l // m) * q
r = l % m

if r:
  ans += q
  s -= q * (m-r)

if s > 0:
  ans += (s + (m-1)) // m

print(ans)

