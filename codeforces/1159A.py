n = input()
s = list(input())
x = m = i = 0
for c in s:
    if c == '-': i-=1
    else: i+=1
    x = min(x, i)
    m = max(m, i)
print(i - x)

