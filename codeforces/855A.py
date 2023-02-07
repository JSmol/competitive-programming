n = int(input())
S = set()
for i in range(n):
    s = input()
    if s not in S:
        S.add(s)
        print("NO")
    else:
        print("YES")


