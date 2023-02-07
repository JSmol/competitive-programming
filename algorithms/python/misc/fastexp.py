mod = int(1e9) + 7

def exp(m, p):
  r = 1
  x = m

  while p > 0:
    if p & 1:
      p -= 1
      r = (r * x) % mod
    else:
      p >>= 1
      x = (x * x) % mod

  return r
