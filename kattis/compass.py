n = int(input())
m = int(input())

a = ((m - n) + 360) % 360
b = ((n - m) + 360) % 360
x = min(a, b)
if (n + x) % 360 == m:
  print(x)
else:
  print(-x)