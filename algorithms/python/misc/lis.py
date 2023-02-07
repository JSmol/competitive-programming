A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
n = len(A)

def bs(L, h, v):
  l = 0
  while l < h:
    m = (h + l) // 2
    if (A[L[m]] >= v):
      h = m
    else:
      l = m + 1

  return l
     
def lis():
  L = [0] * n
  P = [-1] * n
  e = 0
  for i in range(1, n):
    if A[i] < A[L[0]]:
      L[0] = i

    elif A[i] > A[L[e]]:
      P[i] = L[e]
      e += 1
      L[e] = i

    else:
      j = bs(L, e, A[i])
      P[i] = L[j-1]
      L[j] = i

    # printf"iteration {i}")
    # for j in range(e+1):
    #   a = []
    #   k = L[j]
    #   while len(a) <= j:
    #     a.append(A[k])
    #     k = P[k]
    #   print(f"list {j} = {a}")
    # print()

  return e
  
lis()