t = int(input())

for i in range(t):
  s = str(input())
  if s.startswith("Simon says"):
    print(s[10:])
