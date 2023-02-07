import sys
sys.setrecursionlimit(20000)
ww, wb, bw, bb, L = map(int, input().split())
WW = [tuple(map(int, input().split())) for i in range(ww)]
WB = [tuple(map(int, input().split())) for i in range(wb)]
BW = [tuple(map(int, input().split())) for i in range(bw)]
BB = [tuple(map(int, input().split())) for i in range(bb)]
S = tuple(map(int, input().split()))

def b(k):
  k -= 1
  k %= 12
  return k == 1 or k == 4 or k == 6 or k == 9 or k == 11

dp = [[-1 for i in range(22)] for i in range(L+2)]

def g(i, f):
  if i == L-1:
    return 0
  if dp[i][f] != -1:
    return dp[i][f]

  c = S[i] > S[i+1]
  l = min(S[i], S[i+1])
  u = max(S[i], S[i+1])
  d = u - l

  if d == 0:
    dp[i][f] = g(i+1, f)
    return dp[i][f]

  r = 1 << 30
  if b(l) and b(u):
    for e in BB:
      if e[c] == f:
        r = min(r, g(i+1, e[not c]) + e[d+1])

  elif not b(l) and b(u):
    for e in WB:
      if e[c] == f:
        r = min(r, g(i+1, e[not c]) + e[d+1])
    
  elif b(l) and not b(u):
    for e in BW:
      if e[c] == f:
        r = min(r, g(i+1, e[not c]) + e[d+1])
    
  else:
    for e in WW:
      if e[c] == f:
        r = min(r, g(i+1, e[not c]) + e[d+1])

  dp[i][f] = r
  return r

print(min([g(0, i) for i in range(1, 6)]))
    


