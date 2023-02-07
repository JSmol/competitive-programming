from string import ascii_lowercase as al
s = list(input())
ans = 0
a = set("aeiou")
for c in s:
    if c in a:
        ans += 1
    else:
        if c not in al and int(c) % 2:
            ans += 1
print(ans)
