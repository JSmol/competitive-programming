D = {}
for e in input().split():
  e = e[:1]
  if e in D:
    D[e] += 1
  else:
    D[e] = 1

print(max(D.items(), key=lambda a: a[1])[1])

