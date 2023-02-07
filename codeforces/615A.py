n,m=map(int,input().split())
S = set()
for i in range(n):
    for x in input().split():
        S.add(int(x))

if len(S) == m:
    print("YES")
else:
    print("NO")
