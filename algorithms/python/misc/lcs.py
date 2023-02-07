A = [1,2,3,4,3,2,5,6,443,2,543,34,43]
B = [1,2,3,3,2,5,6,52,543,3,433,4,3,2,5,6]

dp = [[-1] * (len(B)+1) for i in range(len(A)+1)]

def lcs(n, m):
  if n == 0 or m == 0:
    return 0
  if dp[n][m] != -1:
    return dp[n][m]
  
  if A[n-1] == B[m-1]:
    dp[n][m] = 1 + lcs(n-1, m-1)
  else:
    dp[n][m] = max(lcs(n-1, m), lcs(n, m-1))

  return dp[n][m]

print(lcs(len(A), len(B)))
