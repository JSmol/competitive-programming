n = int(input())
G = [list() for _ in range(n)]

for i in range(n-1):
  u, v = map(lambda v: int(v) - 1, input().split())
  G[u].append(v)
  G[v].append(u)

print(G)

V = [False] * n
ans = []
st = []
st.append(0)
while st:
  v = st.pop()
  if V[v]:
    continue

  ans.append(v)
  V[v] = True
  for a in G[v]:
    st.append(a)

print("dfs traversal order...")
print(*ans)

