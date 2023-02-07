a, b = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())

def gcd(x, y):
  if y == 0:
    return x
  return gcd(y, x % y)

d = gcd(max(a, b), min(a, b))
dx = a // d
dy = b // d

x1, x2 = min(x1, x2), max(x1, x2)
y1, y2 = min(y1, y2), max(y1, y2)

if x1 <= dx and dx <= x2 and y1 <= dy and dy <= y2:
  c = min((x2 - dx) // dx, (y2 - dy) // dy)
  cx = dx + dx * c
  cy = dy + dy * c

  if x1 <= cx and cx <= x2 and y1 <= cy and cy <= y2:
    cx += dx
    cy += dy

  if cx >= a and cy >= b:
    print("Yes")

  else:
    print("No")
    print(cx, cy)

elif dx >= a and dy >= b:
  print("Yes")
  
else:
  print("No")
  print(dx, dy)

