s = list(input())
t = list(input())

def nck(n, k):
    if n < k:
        return 0
    if k == 0 or n == 0: 
        return 1
    return nck(n-1, k-1) + nck(n-1, k)

d = s.count('+') - s.count('-')
e = t.count('+') - t.count('-')
q = t.count('?') 
x = abs(d - e)
n = (q+1)//2 + (x)//2

# print("(q, x, n) =", (q,x,n))
print(nck(q, n)/(2**q))

