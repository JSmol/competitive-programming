n = int(input())
A = list(map(int, input().split()))
B = sorted(A)

if B[n-1] == B[0]:
    print(0)
    exit()

o = 0
for i in range(n):
    if A[i] == B[n-1] and A[(i+1)%n] == B[0]:
        o = i+1
        break

for i in range(n):
    if A[(i+o)%n] != B[i]:
        print(-1)
        exit()

print((n-o)%n)

