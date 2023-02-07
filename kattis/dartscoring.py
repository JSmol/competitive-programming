from math import atan2
from math import sqrt

# helper functions to sort our points by polar angle from the anchor point
def polar_angle(p0, p1=None):
  if p1 == None: p1 = anchor
  y = p0[1] - p1[1]
  x = p0[0] - p1[0]
  return atan2(y, x)

def distance(p0, p1=None):
  if p1 == None: p1 = anchor
  y = p0[1] - p1[1]
  x = p0[0] - p1[0]
  return sqrt(y ** 2 + x ** 2)

def compare(p0, p1):
  if polar_angle(p0) == polar_angle(p1): return distance(p0) < distance(p1)
  else: return polar_angle(p0) < polar_angle(p1)

# mergesort from mergesort.py
def mergesortcmp(l, cmp):

  if len(l) > 1:
    mid = len(l) // 2
    left = l[:mid]
    right = l[mid:]

    mergesortcmp(left, cmp)
    mergesortcmp(right, cmp)

    i = j = k = 0
    while i < len(left) and j < len(right):
      if cmp(left[i], right[j]):
        l[k] = left[i]
        i += 1
      else:
        l[k] = right[j]
        j += 1

      k += 1

    while i < len(left):
      l[k] = left[i]
      i += 1
      k += 1

    while j < len(right):
      l[k] = right[j]
      j += 1
      k += 1

# determinant of a special 3x3 matrix that magically determines which way we're turning...
def det(p1,p2,p3):
  return (p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0]) 

def convex_hull(points):

  # if there are less than 4 points, the hull is simply all the points
  if len(points) < 4: return points

  # our anchor for the graham scan algorithm
  global anchor

  # we find the lowest, leftmost point to use as our anchor
  index = 0
  for i, point in enumerate(points):

    if point[1] < points[index][1]:
      index = i

    if point[1] == points[index][1] and point[0] < points[index][0]:
      index = i

  anchor = points[index]
  del points[index]

  # we sort our list of points by polar angle relative to anchor
  mergesortcmp(points, compare)

  # graham scan algorithm
  # add the anchor and the first 2 points
  hull = [anchor, points[0], points[1]]

  # scan through the rest of the points
  for point in points[2:]:

    # add point
    hull.append(point)

    # back track while making right turns
    while det(hull[-3], hull[-2], hull[-1]) <= 0 and len(hull) > 3:
      del hull[-2]

  return hull

while True:

  try:
    values = [float(value) for value in raw_input().split()]

    points = []

    for i, value in enumerate(values):
      if i % 2 == 0: points.append((value, values[i+1]))

    n = len(points)

    hull = convex_hull(points)

    s = distance(hull[0], hull[-1])
    for i, point in enumerate(hull[1:]):
      s += distance(point, hull[i])

    print(100 * n / (1 + s))

  except EOFError:
    break
