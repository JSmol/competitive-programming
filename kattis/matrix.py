i = 1
while True:
  try:
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    input()
  except:
    break

  print(f"Case {i}:")
  print(d // ((a * d) - (b * c)), -b // ((a * d) - (b * c)))
  print(-c // ((a * d) - (b * c)), a // ((a * d) - (b * c)))
  i += 1
