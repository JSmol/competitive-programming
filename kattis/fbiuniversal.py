D = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'A':10, 'B':8, 'C':11, 'D':12, 'E':13, 'F':14, 'G':11, 'H':15, 'I':1, 'J':16, 'K':17, 'L':18, 'M':19, 'N':20, 'O':0, 'P':21, 'Q':0, 'R':22, 'S':5, 'T':23, 'U':24, 'V':24, 'W':25, 'X':26, 'Y':24, 'Z':2}
t = int(input())
for _ in range(t):
  j, s = input().split()
  print(j, end=' ')
  d = 0
  d += 2 * D[s[0]]
  d += 4 * D[s[1]]
  d += 5 * D[s[2]]
  d += 7 * D[s[3]]
  d += 8 * D[s[4]]
  d += 10 * D[s[5]]
  d += 11 * D[s[6]]
  d += 13 * D[s[7]]
  if d%27 != D[s[-1]]:
    print("invalid")
  else:
    d = 0
    for i, c in enumerate(s[:-1]):
      d += D[c] * (27**(7-i))
    print(d)