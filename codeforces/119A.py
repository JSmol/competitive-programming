a, b, n = map(int, input().split())

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x%y)

i = 1
while n>0:
    if i%2:
        n -= gcd(n, a)
    else:
        n -= gcd(n, b)
    i+=1

print(i%2)

