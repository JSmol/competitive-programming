D = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
n = int(input())
A = [input() for i in range(n)]
S = list(map(int, list(input())))

for w in A:
  if len(S) != len(w):
    n -= 1
    continue
  for i, c in enumerate(w):
    if c not in D[S[i]]:
      n -= 1
      break
      
print(n)
  