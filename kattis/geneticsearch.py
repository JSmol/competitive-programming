def cnt(t, s):
    i = -1
    c = 0
    while True:
        j = t[i+1:].find(s)
        if j != -1:
            c += 1
            i += j + 1
        else:
            break

    return c
    
while True:
    s = input()
    if s == '0':
        break

    s, t = s.split()

    ans = []
    ans.append(cnt(t, s))

    D = set()
    for i in range(len(s)):
        m = s[:i] + s[i+1:]
        D.add(m)
        
    ans.append(sum([cnt(t, x) for x in D]))

    D = set()
    for i in range(len(s)+1):
        for c in "AGCT":
            m = s[:i] + c + s[i:]
            D.add(m)

    ans.append(sum([cnt(t, x) for x in D]))
        
    print(*ans)
        

