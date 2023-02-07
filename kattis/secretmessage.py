t = int(input())

for _ in range(t):
  s = str(input())

  n = 1
  while len(s) > n ** 2:
    n += 1

  for _ in range(len(s), n ** 2):
    s += '*'

  ans = ""
  for i in range(0, n):
    for j in range(1, n+1):
      index = (n * j)
      if s[len(s) - index + i] != '*':
        ans += s[len(s) - index + i]
      

  

  print(ans)