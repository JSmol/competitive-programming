from string import ascii_lowercase
a = list(ascii_lowercase)
s = input()
i = ans = 0

for c in s:
    d = abs(i - a.index(c))
    if d > 13:
        ans += 26 - d
    else:
        ans += d
    i = a.index(c)

print(ans)
    
