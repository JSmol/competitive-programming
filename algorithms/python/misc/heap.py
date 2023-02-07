from random import randint

def heappush(A, v):
  A.append(v)
  i = len(A)
  while A[i - 1] > A[(i // 2) - 1] and i > 1:
    A[i - 1], A[(i // 2) - 1] = A[(i // 2) - 1], A[i - 1]
    i = i // 2

def heappop(A):
  A[0], A[-1] = A[-1], A[0]
  v = A.pop()
  i = 1
  while True:
    l = i * 2 if (i * 2) - 1 < len(A) else None
    r = (i * 2) + 1 if i * 2 < len(A) else None
    if r and A[l-1] < A[r-1] and A[i-1] < A[r-1]:
      A[i-1], A[r-1] = A[r-1], A[i-1]
      i = r
    elif l and A[i-1] < A[l-1]:
      A[i-1], A[l-1] = A[l-1], A[i-1]
      i = l
    else:
      break

  return v

A = []

for k in range(1234):
  print(f"test {k} starting...")
  n = randint(1, 99999)
  for i in range(randint(1, 99999)):
    heappush(A, randint(0, 99999))

  B = sorted(A, reverse=True)
  for b in B:
    a = heappop(A) 
    if a != b:
      print("its broken :(")