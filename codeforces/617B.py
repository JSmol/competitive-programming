n = int(input())
A = list(map(int, input().split()))

if A.count(1) == 0:
  print(0)
  exit()

i = A.index(1)
c = ans = 1
while i < n:
  if A[i] == 0:
    c += 1
  else:
    ans *= c
    c = 1
  i += 1

print(ans)
