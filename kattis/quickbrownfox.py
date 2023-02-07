t = int(input())

A = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

for i in range(t):
  ans = ""
  s = str(input()).lower()
  for c in A:
    if c not in s:
      ans += c
    
  if ans:
    print("missing", ans)
  else:
    print("pangram")
