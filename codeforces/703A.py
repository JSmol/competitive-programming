n = int(input())
x = y = 0
for i in range(n):
    a, b = map(int, input().split())
    if a < b:
        x+=1
    if a > b:
        y+=1

if x < y:
    print("Mishka")
if x > y:
    print("Chris")
if x == y:
    print("Friendship is magic!^^")
