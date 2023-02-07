n, h = map(int, input().split())
A = list(map(int, input().split()))
ans = n
for a in A:
    if a > h:
        ans+=1

print(ans)
