A = [list(map(int, input().split())) for i in range(4)]
m = int(input())

def transpose():
    for i in range(4):
        for j in range(i+1, 4):
            A[i][j], A[j][i] = A[j][i], A[i][j]

def reflect():
    for r in range(4):
        A[r] = A[r][::-1]

if m == 1:
    transpose()

if m == 2:
    reflect()

if m == 3:
    transpose()
    reflect()

for j in range(4):
    r = A[j]
    for c in range(4):
        i = c
        while i < 4 and r[i] == 0:
            i += 1

        if i < 4 and i > c:
            r[c] = r[i]
            r[i] = 0

        k = c + 1
        while k < 4 and r[k] == 0:
            k += 1
        
        if k < 4 and r[c] == r[k]:
            r[c] = r[c] + r[k]
            r[k] = 0

if m == 1:
    transpose()

if m == 2:
    reflect()

if m == 3:
    reflect()
    transpose()

for i in range(4):
    print(*A[i])
