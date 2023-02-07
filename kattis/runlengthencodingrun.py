c, s = input().split()
s = list(s)
n = len(s)

if c == 'D':
    ans = ""
    for i in range(0, n, 2):
        ans += s[i] * int(s[i+1])

if c == 'E':
    ans = ""
    i = 0
    while i < n:
        c = s[i]
        j = 0
        while i < n and c == s[i]:
            i += 1
            j += 1
        ans += c + str(j)

print(ans)

