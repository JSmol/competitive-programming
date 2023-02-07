n, c = map(int,input().split())
A = list(map(int,input().split()))
p = k = 0
for a in A:
    if a - p > c:
        k = 1
    else:
        k += 1
    p = a

print(k)

