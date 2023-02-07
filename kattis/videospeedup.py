n,p,k = map(int, input().split())
A = list(map(int, input().split()))

q = 0
ans = 0
for i, a in enumerate(A):
  ans += (a-q)*(100+(i)*p)/100
  q = a

ans += (k-q)*(100+n*p)/100
print(ans)

