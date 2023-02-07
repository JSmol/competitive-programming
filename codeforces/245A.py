n = int(input())

a = b = 0
for i in range(n):
  s, x, y = map(int, input().split())
  if s == 1:
    a += x
    a -= y
  else:
    b += x
    b -= y

if a >= 0:
  print("LIVE")
else:
  print("DEAD")
if b >= 0:
  print("LIVE")
else:
  print("DEAD")


