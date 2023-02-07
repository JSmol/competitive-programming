t = int(input())
for i in range(t):
  d, m = map(int, input().split())
  M = list(map(int, input().split()))
  o = 0
  ans = 0
  for a in M:
    if a < 13:
      pass
    elif (o + 13) % 7 == 6:
      ans += 1
    o = (o + a) % 7

  print(ans)