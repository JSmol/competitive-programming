n = int(input())

i = int(n ** (1/9)) + 1
while i >= 1:
  if n % (i ** 9) == 0:
    print(i)
    break
  i -= 1
