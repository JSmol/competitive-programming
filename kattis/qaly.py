n = int(input())

A = [0] * n
for i in range(n):
    x, y = map(float, input().split())
    A[i] = x * y

print(sum(A))
