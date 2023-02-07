n, k = map(int, input().split())
t = 240 - k

i = 0
while t >= 0:
    i += 1
    t -= 5*i

print(min(i-1, n))
