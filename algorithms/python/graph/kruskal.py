def find (a):
  return a if a == A[a] else find(A[a])

def connected (a, b):
  return find(a) == find(b)

def merge (a, b):
  A[find(b)] = find(a)

n, m = map(int, input().split())

# uf
A = [i for i in range(n+1)]

e = [0] * m

for i in range(m):
  e[i] = tuple(map(int, input().split()))

i = 0
G = [[] for _ in range(n)]
e.sort(key=lambda a : a[2])

for p in e:
  if (i == n-1):
    break

  if (connected(p[0], p[1])):
    continue

  merge(p[0], p[1])
  G[p[0]].append(p)
  G[p[1]].append(p)
  i += 1

print(G)