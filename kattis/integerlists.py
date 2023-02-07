for _ in range(int(input())):
    s = input()
    n = int(input())
    a = input().strip('[').strip(']').split(',')
    
    i = 0
    j = n
    p = 1
    for c in s:
        if c == 'R': p ^= 1
        else:
            if p: i += 1
            else: j -= 1

    if j < i: print("error")
    else:
        if p: print('[', ','.join(a[i:j]), ']', sep='')
        else: print('[', ','.join(a[i:j][::-1]), ']', sep='')
