n = int(input())

p = False
A = []
for i in range(n):
    A.append(input())
    if not p and A[i][:2] == "OO":
        p = True
        A[i] = "++" + A[i][2:]
    if not p and A[i][3:] == "OO":
        p = True
        A[i] = A[i][:3] + "++"

if p:
    print("YES")
    print(*A, sep='\n')
else:
    print("NO")


