s = list(input())
n = len(s)
ans = 0
for i in range(n):
    if s[i] == 'Q':
        for j in range(i+1, n):
            if s[j] == 'A':
                for k in range(j+1, n):
                    if s[k] == 'Q':
                        ans += 1
print(ans)
