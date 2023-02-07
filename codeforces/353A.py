n = int(input())
A = [tuple(map(int, input().split())) for i in range(n)]
l = sum([a[0] for a in A])
r = sum([a[1] for a in A])

if l % 2 == 0 and r % 2 == 0:
    print(0)
elif (l % 2 == 1 and r % 2 == 0) or (l % 2 == 0 and r % 2 == 1):
    print(-1)
else:
    for a in A:
        if a[0] % 2 != a[1] % 2:
            print(1)
            exit()
    print(-1)

