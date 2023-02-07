n, m = map(int, input().split())
A = list(map(int, input().split()))
B = [(int(e), i) for i, e in enumerate(input().split())]
A.sort()
B.sort()
ans = [0] * m
i = j = 0
while j < m:
    while i < n and A[i] <= B[j][0]:
        i += 1
    ans[B[j][1]] = i
    j += 1
print(*ans)
