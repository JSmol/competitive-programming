A = [list("qwertyuiop"), list("asdfghjkl"), list("zxcvbnm")]
t = int(input())

while (t > 0):
    t -= 1

    s, l = input().split()
    D = [input() for _ in range(int(l))]

    S = []
    for c in s:
        n = 0
        while c not in A[n]: n += 1
        m = A[n].index(c)
        S.append((n, m))
       
    ans = []
    for w in D:
        d = 0
        for i, c in enumerate(w):
            n = 0
            while c not in A[n]: n += 1
            m = A[n].index(c)
            d += abs(S[i][0] - n)
            d += abs(S[i][1] - m)
        ans.append((d, w))

    ans.sort()
    for a in ans:
        print(*reversed(a))
