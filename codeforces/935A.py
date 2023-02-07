n = int(input())

S = set()
S.add(1)
i = 2
while i*i <= n:
    if n%i == 0:
        S.add(i)
        S.add(n/i)
    i+=1

print(len(S))
