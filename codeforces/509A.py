def f(x, y):
    if (x == 1 or y == 1):
        return 1
    return f(x-1, y) + f(x, y-1)

n = int(input())
print(f(n, n))
