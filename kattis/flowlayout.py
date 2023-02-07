while True:
  m = int(input())
  if m == 0:
    break

  A = []
  while True:
    A.append(tuple(map(int, input().split())))
    if A[-1][0] == -1 and A[-1][1] == -1:
      A = A[:-1]
      break

  ans = [0, 0]
  l = 0
  h = 0
  for a in A:
    l += a[0]
    if l > m:
      ans[0] = max(ans[0], l - a[0])
      ans[1] += h
      h = a[1]
      l = a[0]

    h = max(h, a[1])

  ans[0] = max(ans[0], l)
  ans[1] += h  
  print(*ans, sep=' x ')

