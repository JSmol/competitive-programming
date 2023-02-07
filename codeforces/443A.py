s = input().split()
S = set()

if len(s) == 1 and len(s[0]) == 2:
  print(0)
elif len(s) == 1 and len(s[0]) == 3:
  print(1)
else:
  S.add(s[0][1:2])

  for e in s[1:]:
    S.add(e[0:1])

  print(len(S))
