n = int(input())

X = set()
Y = set()
for i in range(n):
  x, y = map(int, input().split())
  X.add(x)
  Y.add(y)

print(min(len(X), len(Y)))
