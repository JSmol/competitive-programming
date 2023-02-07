a, b = map(int, input().split())
x = min(a, b)
y = max(a, b) - x
y //= 2

print(x, y)
