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

/*  O(n sqrt(n)) Bipartite graph matching
 *  match().fst = # matches
 *  match().snd = match details (L to R, -1 means no match)
 */

struct matching {
  int l, r, p; vector<int> M, U, D; vector<vector<int>> A; queue<int> Q;
  matching (int l, int r) : l(l), r(r), D(r+1), A(r) {}
  void add_edge(int u, int v) { A[v].push_back(u); }
  bool bfs() {
    for (int v = 0; v < r; v++) if (!U[v]) D[v] = p, Q.push(v);
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      if (D[v] != D[r]) for (int u : A[v]) if (D[M[u]] < p)
        D[M[u]] = D[v] + 1, Q.push(M[u]);
    }
    return D[r] >= p;
  }
  int dfs(int v) {
    if (v == r) return 1;
    for (int u : A[v]) if (D[M[u]] == D[v] + 1 and dfs(M[u])) 
      return M[u] = v, 1;
    D[v] = D[r]; return 0;
  }
  pair<int, vector<int>> match() {
    int res = 0; M.assign(l, r), U.assign(r+1, 0);
    for (p = 0; bfs(); p = D[r] + 1) for (int v = 0; v < r; v++)
      if (!U[v] and dfs(v)) U[v] = 1, res++;
    replace(all(M), r, -1); return {res, M};
  }
};

typedef Point<ld> P;
const ld pi = acos(-1);
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<ld> x(n), y(n), a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  auto g = [&] (P p, P q, ld ang) {
    return abs(pi/2.0 - (q-p).angle()) < ang/2;
  };

  auto f = [&] (ld ang) {
    matching m(n, n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (g(P(x[i], y[i]), P(a[j], b[j]), ang))
          m.add_edge(i, j);

    return m.match().fst == n;
  };

  ld l = 0, r = pi;
  while (r - l > 1e-12) {
    ld m = (r + l) / 2.0;
    (f(m) ? r : l) = m;
  }

  ld ans = l * 180.0 / pi;
  cout << fixed << setprecision(9) << ans << endl;
}

