n = int(input())
A = []
for i in range(n):
    A.append(tuple(map(int, input().split())))

ans = 0
for i in range(n):
    for j in range(n):
        if i == j:
            continue

        if A[i][0] == A[j][1]:
            ans+=1
print(ans)
