n = int(input())
A = list(map(int, input().split()))
i = 0
j = n-1
a = b = t = 0
while i <= j:
    if A[i] > A[j]:
        if t % 2:
            a += A[i]
        else:
            b += A[i]
        i += 1
    else:
        if t % 2:
            a += A[j]
        else:
            b += A[j]
        j -= 1

    t = not t

print(b, a)
