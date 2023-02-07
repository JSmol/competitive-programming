k, r = map(int, input().split())
m = k
i = 1
while m%10 != r and m%10 != 0:
    m += k
    i += 1
print(i)
