a,b=map(int,input().split())
x,y,z=0,0,0
for i in range(1,7):
    if abs(a-i) < abs(b-i):
        x+=1
    elif abs(b-i) < abs(a-i):
        z+=1
    else:
        y+=1
print(x,y,z)
