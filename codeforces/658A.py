n, c = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))
a = b = 0
s = t = 0

for i in range(n):
  a += B[i]
  s += max(A[i]-c*a, 0)

A = A[::-1]
B = B[::-1]

for i in range(n):
  b += B[i]
  t += max(A[i]-c*b, 0)

if s > t:
  print("Limak")
if s < t:
  print("Radewoosh")
if s == t:
  print("Tie")
