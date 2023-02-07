a, b, c = map(int, input().split())
print(min(a+b+c, a+b+a+b, a+c+c+a, b+c+c+b))

