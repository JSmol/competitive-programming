n = int(input())
A = [0] * n
for i in range(n):
  A[i] = int(input())

A.sort(reverse=True)
i = 0
while i < n and A[i] >= i+1:
  i += 1

print(i)