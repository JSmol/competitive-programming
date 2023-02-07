a,b,c,d = map(int,input().split())
ans = 0
x = min(a,c,d)
ans += 256*x
a -= x
x = min(a,b)
ans += 32*x
print(ans)
