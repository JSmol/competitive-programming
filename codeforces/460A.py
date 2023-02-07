n, m = map(int, input().split())

i = 1
while n > 0:
    n-=1
    if i % m == 0:
        n+=1
    i+=1

print(i-1)
