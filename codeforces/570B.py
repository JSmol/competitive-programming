n, a = map(int, input().split())

if n == 1:
    print(1)
    exit()

m = n // 2
if a <= m:
    print(a+1)
else:
    print(a-1)
