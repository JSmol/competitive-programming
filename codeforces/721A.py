n = int(input())
s = list(input())

A = []
i = 0
while i < n:
    if s[i] != "B":
        i+=1
        continue

    j = i+1
    while j < n and s[j] == "B":
        j+=1

    A.append(j-i)
    i = j

print(len(A))
print(*A)
