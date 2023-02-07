n = int(input())
A = list(map(int, input().split()))
A = A[1:]
B = list(map(int, input().split()))
B = B[1:]

S = set()
for a in A:
    S.add(a)
for b in B:
    S.add(b)

if len(S) == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
