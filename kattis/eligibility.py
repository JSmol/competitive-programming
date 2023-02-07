n = int(input())
for i in range(n):
    a,b,c,d = input().split()
    b = b.split('/')
    c = c.split('/')

    ans = -1
    if (int(b[0]) >= 2010): ans = 1
    if (int(c[0]) >= 1991): ans = 1
    if (ans < 0 and int(d) > 40): ans = 0
    
    if (ans == 0): print(f"{a} ineligible")
    if (ans <  0): print(f"{a} coach petitions")
    if (ans >  0): print(f"{a} eligible")
    
