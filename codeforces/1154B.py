n = int(input())
A = list(map(int, input().split()))
A.sort()

if A[0] != A[-1]:
    for d in range(202):
        w = False
        if A[0] + d == A[-1]:
            w = True
            for i in range(n):
                if A[i] + d != A[-1] and A[i] != A[-1]:
                    w = False
                    break
        
        if w:
            print(d)
            exit()

        if A[0] + d == A[-1] - d:
            w = True
            for i in range(n):
                if A[i] + d != A[-1] - d and A[i] != A[-1] - d and A[i] - d != A[-1] - d:
                    w = False
                    break

        if w:
            print(d)
            exit()
    print(-1)
    exit()
print(0)
