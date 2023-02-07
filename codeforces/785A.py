n = int(input())

ans = 0
for i in range(n):
    s = input()
    if s[0:1] == "T":
        ans += 4
    if s[0:1] == "C":
        ans += 6
    if s[0:1] == "O":
        ans += 8
    if s[0:1] == "D":
        ans += 12
    if s[0:1] == "I":
        ans += 20

print(ans)
