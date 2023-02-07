while True:
    n = int(input())
    if n == 0:
        break

    M = dict()
    for _ in range(n):
        x = input().split()
        for i in range(1, len(x)):
            if x[i] in M:
                M[x[i]].add(x[0])
            else:
                M[x[i]] = set()
                M[x[i]].add(x[0])

    for k in sorted(M.keys()):
        print(k, *sorted(M[k]))
    print()

