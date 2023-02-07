from random import randrange
from math import hypot, inf
from time import time

def timer(f, *args):
  s = time()
  r = f(*args)
  t = time()
  return r, t - s

def dist(a, b):
  return hypot(a[0]-b[0], a[1]-b[1])

def nieve(A):
  d = inf
  for i, a in enumerate(A):
    for j, b in enumerate(A):
      if i != j:
        d = min(d, dist(a, b))
  return d

# assumes A is sorted
def f(A):
  n = len(A)
  if (n <= 3):
    return nieve(A)

  d = min(f(A[:n//2]), f(A[n//2:]))

  S = []
  for p in A:
    if abs(p[0] - A[n//2][0]) < d:
      S.append(p)

  S.sort(key=lambda e:e[1])
  for i in range(len(S)):
    j = i + 1
    while j < len(S) and abs(S[j][1] - S[i][1]) < d:
      d = min(d, dist(S[j], S[i]))
      j += 1
    
  return d

def test(t, n):
  a1, a2 = 0, 0
  for i in range(t):
    A = []
    for j in range(n):
      A.append((randrange(-1e6, 1e6), randrange(-1e6, 1e6)))

    A.sort()
    d1, t1 = timer(f, A)
    d2, t2 = timer(nieve, A)
    print(f"test {i} complete:")
    print(f"my func result = {d1}, time = {t1}")
    print(f"nieve result = {d2}, time = {t2}")
    assert(d1 == d2)

    a1 += t1
    a2 += t2

  print(f"{t} tests complete with n = {n}, points in range{-1e6, 1e6})") 
  print(f"average preformence my func = {a1/t}")
  print(f"average preformance nieve = {a2/t}")

test(100, int(1e3))
