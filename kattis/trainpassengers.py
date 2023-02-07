c, n = map(int, input().split())

p = 0

for _ in range(n):
  l, e, s = map(int, input().split())
  p -= l
  if p < 0:
    print("impossible")
    exit()
  p += e
  if p > c:
    print("impossible")
    exit()
  if p != c and s > 0:
    print("impossible")
    exit()

if p != 0:
  print("impossible")
  exit()

print("possible")



