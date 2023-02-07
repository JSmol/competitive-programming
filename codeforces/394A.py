s = input()

A = [0,0,0]

i = 0
k = 0

for c in s:
  if c == '+' or c == '=':
    i += 1
    continue

  if c == '|':
    A[i] += 1

if A[0] + A[1] == A[2]:




