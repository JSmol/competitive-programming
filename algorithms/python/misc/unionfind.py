n = 12
A = [i for i in range(n)]

def find (a):
  return a if a == A[a] else find(A[a])

def connected (a, b):
  return find(a) == find(b)

def merge (a, b):
  A[find(b)] = find(a)

merge(1,4)
merge(1,7)
merge(3,4)
merge(2,4)
merge(2,8)
merge(6,9)

print(connected(2,4))
print(connected(3,8))
print(connected(1,8))
print(connected(6,8))