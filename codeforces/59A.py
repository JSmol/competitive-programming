a = "qwertyuiopasdfghjklzxcvbnm"
s = input()
l = u = 0
for c in s:
  if c in a:
    l+=1
  else:
    u+=1

if l >= u:
  print(s.lower())
else:
  print(s.upper())
