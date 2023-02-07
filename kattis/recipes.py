t = int(input())
c = 0
while c < t:
    c += 1
    
    r, p, d = map(int, input().split())
    A = [tuple(input().split()) for _ in range(r) ]
    
    for e in A:
        if e[2] == "100.0":
            v = float(e[1])

    s = v * d / p
    ans = []
    for e in A:
        ans.append((e[0], (float(e[2]) / 100) * s))

    print(f"Recipe # {c}")
    for a in ans:
        print(a[0], round(a[1], 1))
    print("----------------------------------------")
    
