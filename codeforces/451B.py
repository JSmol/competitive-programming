n=int(input())
A=list(map(int, input().split()))
B=sorted(A)

s = t = -1
for i in range(n):
    if A[i] != B[i]:
        s = i
        break

if s == -1:
    print("yes")
    print(1, 1)
    exit()

for i in range(n-1, -1, -1):
    if A[i] != B[i]:
        t = i+1
        break

A = A[:s] + A[s:t:][::-1] + A[t:]
if A == B:
    print("yes")
    print(s+1,t)
else:
    print("no")



