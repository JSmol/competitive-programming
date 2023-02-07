n,d=map(int,input().split())
ans = c = 0
for i in range(d):
    s = input()
    if s.count('1') == n:
        ans = max(ans, c)
        c = 0
    else:
        c += 1

print(max(ans, c))
