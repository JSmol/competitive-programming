s = list(input())

i = 0
while s[i] != "[":
    i+=1
    if i == len(s):
        print(-1)
        exit()

s = s[i:]

i = 1
while s[i] != ":":
    i+=1
    if i == len(s):
        print(-1)
        exit()

s = s[0]+s[i:]

i = len(s)-1
while s[i] != "]":
    i-=1
    if i < 0:
        print(-1)
        exit()

s = s[:i+1]

i = len(s)-2
while s[i] != ":":
    i-=1
    if i < 0:
        print(-1)
        exit()

s = s[:i+1]+s[-1]
print(s)




