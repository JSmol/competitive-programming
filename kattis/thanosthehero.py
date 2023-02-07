n = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(n-1, 0, -1):
  if A[i] <= A[i-1]:
    k = A[i-1] - A[i] + 1
    ans += k
    A[i-1] -= k
    if A[i-1] < 0:
      print(1)
      exit()

if A[0] < 0:
  print(1)
else:
  print(ans)
