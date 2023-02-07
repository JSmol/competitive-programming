from string import ascii_lowercase
from random import randint, choices
from time import time

# trie[pos][char] = next row
trie = [[0] * 27]

# get index of next letter
def index(c):
  return ascii_lowercase.find(c)

# add key to trie
def add_key(w, v):
  i, j = 0, 0
  while j < len(w):
    c = index(w[j])
    k = trie[i][c]
    if k:
      i = k
      j += 1
    else:
      trie[i][c] = len(trie)
      trie.append([0] * 27)

  trie[i][26] = v

def find(w):
  i = 0
  for l in w:
    c = index(l)
    i = trie[i][c]
    if not i:
      return None
  
  return trie[i][26]

def test_correctness():
  # n random words
  # lengths range from 2, 20
  D = {}
  n = int(1e5)
  for i in range(int(n)):
    s = ''.join(choices(ascii_lowercase, k=randint(2, 20)))

    # random values for each string
    v = randint(1, int(1e6)) 

    # we compare the trie to python dictionary
    # for correctness
    D[s] = v
    add_key(s, v)

  # query the trie for every string in dictionary
  for i, s in enumerate(D):
    v1 = D[s]
    v2 = find(s)

    assert(v1 == v2)

  for i in range(k):
    # just querying for random words
    # this code basically does nothing but whatever.
    s = ''.join(choices(ascii_lowercase, k=randint(2, 20)))
    find(s)

# n = # of strings
# k = # of queries
def test_preformance(n, k):
  start = time()
  D = {}
  for i in range(int(n)):
    s = ''.join(choices(ascii_lowercase, k=randint(2, 20)))
    v = randint(1, int(1e6)) 
    D[s] = v

  t1 = time() - start
  print(f"dictionary complete in {t1}")

  start = time()
  for i in range(int(n)):
    s = ''.join(choices(ascii_lowercase, k=randint(2, 20)))
    v = randint(1, int(1e6)) 
    add_key(s, v)
  
  t2 = time() - start
  print(f"trie complete in {t2}")

  qt1, qt2 = 0, 0
  print(f"begining queries...")
  for i in range(k):
    s = ''.join(choices(ascii_lowercase, k=randint(2, 20)))
    
    start = time()
    find(s)
    qt1 += time() - start

    start = time()
    D.get(s)
    qt2 += time() - start

  print(f"{k} queries complete")
  print(f"trie average preformance = {qt1/k}")
  print(f"dict average preformance = {qt2/k}")

test_preformance(int(1e5), int(1e6))
