n = int(input())
l = 0
for i in range(n):
    x, d = input().split()
    x = int(x)
    if (d == "East" or d == "West") and (l != 0 and l != 20000):
        continue
    if (d == "East" or d == "West") and (l == 0 or l == 20000):
        print("NO")
        exit()

    if d == "South":
        l += x
    if d == "North":
        l -= x

    if l < 0 or l > 20000:
        print("NO")
        exit()

if l == 0:
    print("YES")
else:
    print("NO")
