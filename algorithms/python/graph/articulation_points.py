n, m = map(int, input().split())
G = [list() for _ in range(n)]

for i in range(m):
  u, v = map(int, input().split())
  G[v].append(u)
  G[u].append(v)

print(G)

t = 1
art = set()
L = [-1] * n
V = [False] * n
def dfs(v):
  global t
  V[v] = True
  L[v] = l = t
  t += 1

  for a in G[v]:
    if not V[a]:
      dfs(a)

      if L[a] > l:
        art.add(v)

    else:
      L[v] = min(L[v], L[a])

dfs(1)
print(L)
print(len(art))