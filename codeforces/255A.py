n = int(input())
A = list(map(int, input().split()))
a = b = c = 0
for i in range(n):
    if i % 3 == 0:
        c += A[i]
    if i % 3 == 1:
        a += A[i]
    if i % 3 == 2:
        b += A[i]

d = max([a,b,c])
if a == d:
    print("biceps")
if b == d:
    print("back")
if c == d:
    print("chest")
