n,b,a = map(int,input().split())
A = list(map(int, input().split()))
m = a
ans = 0
for i in range(n):
    if A[i] == 1:
        if b > 0 and a < m:
            b -= 1
            a += 1
        elif a > 0:
            a -= 1
        elif b > 0:
            b -= 1
        else:
            break
    else:
        if a > 0:
            a -= 1
        elif b > 0:
            b -= 1
        else:
            break
    ans = i+1

print(ans)
