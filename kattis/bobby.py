from math import factorial as f

def nCk(n, k):
  if n == k:
    return 1
  return f(n) / (f(k) * f(n - k))

t = int(input())

for _ in range(t):
  r, s, x, y, w = map(int, input().split())

  ps = (s - (r-1)) / s
  pf = (r-1) / s

  ev = 0
  for i in range(y - x + 1):
    ev += (ps ** (x+i)) * (pf ** (y - (x+i))) * nCk(y, x+i)

  if ev * w <= 1:
    print("no")
  else:
    print("yes")
  
  