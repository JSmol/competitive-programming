n = int(input())
A = list(map(int, input().split()))
C = [0] * (2*n+2)
for a in A:
    C[a] += 1

ans = c = 0
for i in range(2*n+2):
    ans += c
    if C[i] > 1:
        c += C[i] - 1
    if C[i] == 0 and c > 0:
        c -= 1

print(ans)
