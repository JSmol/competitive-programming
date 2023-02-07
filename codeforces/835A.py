s, a, b, c, d = map(int, input().split())

e = a*s + 2*c
f = b*s + 2*d

if (e < f):
    print("First")
if (e > f):
    print("Second")
if (e == f):
    print("Friendship")
