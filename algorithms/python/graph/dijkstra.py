from math import inf, nan
from heapq import heappush, heappop

n, m = map(int, input().split())
G = {i:[] for i in range(n)}

for i in range(m):
  a, b, c = map(int, input().split())
  G[a].append((b, c))
  G[b].append((a, c))

def dijkstra (a, b):
  D = [-1] * n
  Q = [(0, a)]

  while Q:
    v = heappop(Q)

    if D[v[1]] != -1:
      continue

    D[v[1]] = v[0]
    for u in G[v[1]]:
      heappush(Q, (v[0] + u[1], u[0]))
  
  return D[b]

# D = [inf] * n
# P = [-1] * n
# D[0] = 0
# U = [(0, 0)]

# while U:
#   v = heappop(U)
  
#   for w in G[v[1]]:
#     d = D[v[1]] + w[1]
#     if D[w[0]] > d:
#       D[w[0]] = d
#       P[w[0]] = v[1]
#       heappush(U, (d, w[0]))

# ans = [1]
# while ans[-1] != 0 and ans[-1] != -1:
#   ans.append(P[ans[-1]])

# print("path from 0 to 1 is")
# print(*reversed(ans))
