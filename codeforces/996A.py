n = int(input())

c = 0
if n >= 100:
    c += n//100
    n%=100

while n > 0:
    c+=1
    if n >= 20:
        n-=20
        continue
    if n >= 10:
        n-=10
        continue
    if n >= 5:
        n-=5
        continue
    if n >= 1:
        n-=1
        continue

print(c)
