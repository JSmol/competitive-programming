n = int(input())
A = [1] * int(1e6*2+1)
ans = []
i = 2
while i <= int(1e6*2) and len(ans) < n:
    if A[i]:
        ans.append(i)
        k = 2 * i
        while k <= int(1e6*2):
            A[k] = 0
            k += i
    i+=1

assert(len(ans) == n)
print(*ans)
