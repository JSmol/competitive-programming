n = int(input())

ans = 0
p = -1
for i in range(n):
    x = int(input())
    if x != p:
        ans+=1
    p = x

print(ans)
