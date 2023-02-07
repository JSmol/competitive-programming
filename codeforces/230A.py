s, n = map(int, input().split())
A = []
for i in range(n):
    A.append(tuple(map(int, input().split())))

A.sort()
for a in A:
    if s > a[0]:
        s+=a[1]
    else:
        print("NO")
        exit()
print("YES")

