s = input()

n = s.count('n')
i = s.count('i')
e = s.count('e')
t = s.count('t')

A = []
A.append(i)
A.append(e // 3)
A.append(t)

m = min(A)

if (n > m * 3 - (m - 1)):
  print(m)
else:
  print(max(0, ((n+1)//(3-1)) - 1))


