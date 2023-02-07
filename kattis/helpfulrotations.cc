#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
double time() { return double(clock()) / CLOCKS_PER_SEC; }

typedef long double ld;
#define double ld

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x=0, T y=0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }
  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P p) const { return x*p.y - y*p.x; }
  T cross(P a, P b) const { return (a-*this).cross(b-*this); }
  T dist2() const { return x*x + y*y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this/dist(); } // makes dist()=1
  P perp() const { return P(-y, x); } // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; 
  }
};

template<class P>
vector<P> intersectiline(P c, ld r, P a, P b) {
  P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
  double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
  if (h2 < 0) return {};
  if (h2 == 0) return {p};
  P h = ab.unit() * sqrt(h2);
  return {p - h, p + h};
}

template<class P>
int inter(P c, ld r, P a, P b) {
  auto pnts = intersectiline(c, r, a, b);
  for (auto p : pnts) {
    if ((p - a).dot(b - a) >= 0 and (p - b).dot(a - b) >= 0) return 1;
  }
  return 0;
}

typedef Point<ld> P;
const ld pi = acos(-1);
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, s; ld t, a; cin >> n >> s >> t >> a;
  vector<tuple<P, ld, ld>> A(n);
  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    auto& [p, r, w] = A[i];
    cin >> p.x >> p.y >> r >> w;
    char x; cin >> x;
    R[i] = (x == 't');
  }

  if (R[s]) {
    cout << 0 << endl;
    return 0;
  }

  priority_queue<tuple<ld, int, int>> Q;
  vector<vector<ld>> D(n, vector<ld>(n, -1));

  auto cost = [&] (ld dist) {
    ld m = dist / 2.0;
    return 2*abs(sqrt((2.0*m) / a));
  };

  vector<vector<int>> memo(n, vector<int>(n, -1));
  auto chk = [&] (int v, int u) {
    if (v > u) swap(v, u);
    if (memo[v][u] != -1) return memo[v][u];
    auto [p1, r1, w1] = A[v];
    auto [p2, r2, w2] = A[u];
    for (int i = 0; i < n; i++) {
      if (i == v or i == u) continue;
      auto [p, r, w] = A[i];
      if (inter(p, r, p1, p2)) {
        return memo[v][u] = 0;
      }
    }
    return memo[v][u] = 1;
  };

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      chk(i, j);

  auto adist = [&] (ld a1, ld a2) {
    ld res = (a2 - a1);
    while (res < 0) res += 2*pi;
    while (res >= 2*pi) res -= 2*pi;
    return res;
  };

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (!chk(i, j)) continue;
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }

  auto move = [&] (int v, ld a1, ld d) {
    auto [p1, r1, w1] = A[v];
    if (abs(w1) < 1e-12) return;
    for (auto& u : adj[v]) {
      auto [p2, r2, w2] = A[u];
      ld dist = (p2 - p1).dist() - r1 - r2;
      ld a2 = (p2 - p1).angle();

      if (w1 < 0) Q.push({d - cost(dist) - adist(a2, a1) / abs(w1), u, v});
      else Q.push({d - cost(dist) - adist(a1, a2) / abs(w1), u, v});
    }
  };

  move(s, t, 0);

  while (!Q.empty()) {
    auto [d, v, u] = Q.top(); Q.pop();
    if (D[v][u] >= 0) continue;
    D[v][u] = -d;

    if (R[v]) {
      cout << fixed << setprecision(9) << -d << endl;
      return 0;
    }

    auto [p1, r1, w1] = A[v];
    auto [p2, r2, w2] = A[u];
    move(v, (p2 - p1).angle(), d);
  }

  cout << "request repair bot assistance" << endl;
}

