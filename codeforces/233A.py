n=int(input())
if n % 2 != 0:
    print(-1)
else:
    A = []
    for i in range(n):
        if i % 2 == 0:
            A.append(i+2)
        else:
            A.append(i)
    print(*A)
