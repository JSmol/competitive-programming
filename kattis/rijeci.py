k = int(input()) - 1
b = 1
a = 0

while k > 0:
    t = b
    b = t + a
    a = t
    k -= 1

print(a, b)

