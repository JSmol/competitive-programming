n = int(input())

for i in range(n//2):
    print("*"*(n//2-i) + "D"*(2*i+1) + "*"*(n//2-i))

print("D"*n)

for i in range(n//2):
    print("*"*(i+1) + "D"*(n-2*(i+1)) + "*"*(i+1))
