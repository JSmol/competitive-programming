n = int(input())
A = [(int(a), i+1) for i, a in enumerate(input().split())]
A.sort()
for i in range(n//2):
    print(A[i][1], A[n-i-1][1])
