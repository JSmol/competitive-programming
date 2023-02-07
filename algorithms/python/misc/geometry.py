# 2d geometry stuff...
# thanks Howard :^)
# throughout this code:
# points are tuples (x, y)
# lines are defined by 2 points
# circles are difined by a point and radius

# warn! some of it untested still.....

from math import sqrt, hypot

# EPSILON, when working with floating point.
EPSILON = 1e-8

def dist(a, b):
  return hypot(a[0]-b[0], a[1]-b[1])

def triangle_area(a, b, c):
  return ((b[0] - a[0])*(c[1] - a[1]) - (c[0] - a[0])*(b[1] - a[1])) / 2

# area of triangle given lengths of 3 sides
def heron(a, b, c):
  if a < b:
    a, b = b, a
  if a < c:
    a, c = c, a
  if b < c:
    b, c = c, b
  if c < a - b:
    return -1
  return sqrt((a+b+c)*(c-a+b)*(a+b-c)*(a+b-c)) / 4

# returns distance from point c to iline a, b
def dist_line(a, b, c):
  l = (b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2
  s = ((a[1] - c[1])*(b[0] - a[0]) - (a[0] - c[0])*(b[1] - a[1])) / l
  return abs(sqrt(l) * s)

# returns 0, 0 if the points are colinear
# returns p, r if the points define a circle
def circle_3pnts(a, b, c):
  d = 2*(b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0])
  if abs(d) < EPSILON:
    return 0

  e = (b[0] - a[0])*(a[0] + b[0]) + (b[1] - a[1])*(a[1] + b[1])
  f = (c[0] - a[0])*(a[0] + c[0]) + (c[1] - a[1])*(a[1] + b[1])

  p = (((c[1] - a[1])*e - (b[1] - a[1])*f) / d,
       ((b[0] - a[0])*f - (c[0] - a[0])*e) / d)
  r = dist(p, a)
  return p, r

# a, b is points defining a line
# c, d is points defining another line
# returns p if the lines intersect at p
# returns 0 if the lines do not intersect
# returns -1 if the lines intersect at infinitely many points
def intersect_iline(a, b, c, d):
  n = (d[0] - c[0])*(a[1] - c[1]) - (a[0] - c[0])*(d[1] - c[1])
  d = (b[0] - a[0])*(d[1] - c[1]) - (d[0] - c[0])*(b[1] - a[1])

  if abs(d) > EPSILON:
    r = n / d
    p = (a[0] + r*(b[0] - a[0]), a[1] + r*(b[1] - a[1]))
    return p
  else:
    return 0 if abs(n) > EPSILON else -1

# same as iline but for line segments
# doesn't check for overlap points like Howards code
def intersect_lineseg(a, b, c, d):
  n = (d[0] - c[0])*(a[1] - c[1]) - (a[0] - c[0])*(d[1] - c[1])
  m = (b[0] - a[0])*(a[1] - c[1]) - (a[0] - c[0])*(b[1] - a[1])
  d = (b[0] - a[0])*(d[1] - c[1]) - (d[0] - c[0])*(b[1] - a[1])

  if abs(d) >= EPSILON:
    r = n / d
    s = m / d
    if (0-EPSILON <= r and r <= 1+EPSILON and
        0-EPSILON <= s and s <= 1+EPSILON):
      p = (a[0] + r*(b[0] - a[0]), a[1] + r*(b[1] - a[1]))
      return p
    else:
      return 0
  else:
    return 0 if abs(n) > EPSILON else -1

# a and b are points defining a line
# c is the centre of a circle and r its radius
# returns 0, 0 if there is no intesection
# returns p1, 0 or p1, p2 if there is an intersection
def intersect_iline_circle(a, b, c, r):
  a = (a[0] - c[0], a[1] - c[1])
  b = (b[0] - c[0], b[1] - c[1])
  dx = b[0] - a[0]
  dy = b[1] - a[1]
  dr = dx ** 2 + dy ** 2
  d = a[0]*b[1] - b[0]*a[1]
  desc = r ** 2 * dr - d ** 2

  if (abs(desc) < EPSILON):
    p = (c[0] + (d*dy) / dr, c[1] + (-d*dx) / dr)
    return p, 0
  elif desc < 0:
    return 0, 0

  sgn = -1 if dy < -EPSILON else 1
  p1 = (c[0] + (d*dy + sgn*dx*sqrt(desc)) / dr, 
        c[0] + (-d*dx + sgn*abs(dy)*sqrt(desc)) / dr)
  p2 = (c[0] + (d*dy - sgn*dx*sqrt(desc)) / dr, 
        c[0] + (-d*dx - sgn*abs(dy)*sqrt(desc)) / dr)

  return p1, p2

# c is the centre of a circle, r is the radius
# returns 0, 0 if there are no intersections
# returns 1, 0 if there are infinite intersections
# returns p1, 0 or p1, p2 if there are finite intersections
def intersect_circle_circle(c1, r1, c2, r2):

  if (abs(r1) < EPSILON and abs(r2) < EPSILON):
    if (abs(c1[0] - c2[0]) < EPSILON and 
        abs(c1[1] - c2[1]) < EPSILON):
      return (c1[0], c1[1])
    else:
      return 0, 0

  d = hypot(c1[0] - c2[0], c1[1] - c2[1])

  if (abs(c1[0] - c2[0]) < EPSILON and 
      abs(c1[1] - c2[1]) < EPSILON and
      abs(r1[1] - r2[1]) < EPSILON):
    return 1, 0

  if d > r1 + r2 + EPSILON:
    return 0, 0

  if d < abs(r1 - r2) - EPSILON:
    return 0, 0

  a = (r1 ** 2 - r2 ** 2  + d ** 2) / (2 * d)
  h = sqrt(abs(r1 ** 2 - a ** 2))
  p = (c1[0] + a / d * (c2[0] - c1[0]), 
       c1[1] + a / d * (c2[1] - c1[1]))

  p1 = (p[0] + h / d * (c2[1] - c1[1]),
        p[1] - h / d * (c2[0] - c1[0]))

  p2 = (p[0] - h / d * (c2[1] - c1[1]),
        p[1] + h / d * (c2[0] - c1[0]))

  if (abs(h) < EPSILON):
    return p1, 0

  return p1, p2
