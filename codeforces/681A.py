n=int(input())
for i in range(n):
    s,x,y = input().split()
    if int(y) > int(x) and int(x) >= 2400:
        print("YES")
        exit()

print("NO")

