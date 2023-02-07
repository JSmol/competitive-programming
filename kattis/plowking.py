n, m = map(int, input().split())

def w(k):
  k -= 1
  return (k * (k - 1)) // 2 + 1

def f(k):
  return (k * (k - 1)) // 2

k = 1
ans = 0

while n - k > 0 and m - f(k+1) > n-k-1:
  k += 1
  ans += w(k)

ans += w(k+1)
for i in range(n - (k+1)):
  ans += m - i

print(ans)
