from math import ceil 

def gcd(a, b):
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a != 0:
        q, b, a = b // a, a, b % a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0

tc = int(input())
for i in range(tc):
    ws,hs,wl,hl,xl,yl = map(int, input().split())
    ws = ws-wl
    hs = hs-hl
    c = yl-xl
    # print("(xl, yl) =", (xl, yl));
    d, s, t = gcd(hs, -ws)
    if c % d == 0:
        k = c//d
        s = k*s
        t = k*t

        # print(f"{hs} ({s} + {ws//d}n) - ({ws} ({t} + {hs//d}n) = {c}");
        # print("s, t, c, k =", (s, t, c, k));

        n = (-s*d)//ws-1
        xans = yans = -1
        # print(f"n = {n}");
        # xans = (s+n*(ws//d))*hs - yl

        while xans < 0 and yans < 0:
            xans = (s+n*(ws//d))*hs - yl
            yans = (t+n*(hs//d))*ws - xl
            # print(xans, yans);
            assert(xans == yans)
            n += 1

        print(xans)
    else:
        print("Johnny will die waiting")
    # print()
