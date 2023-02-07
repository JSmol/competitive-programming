#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

#define double long double
// geometry basics from KTH competitive programming
// https://github.com/kth-competitive-programming/kactl
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct vec2 {
	explicit vec2(T x, T y) : x(x), y(y) {}
  typedef vec2 V;
  T x, y;
	bool operator<(V w) const { return tie(x, y) < tie(w.x, w.y); }
	bool operator==(V w) const { return tie(x,y) == tie(w.x,w.y); }
	V operator+(V w) const { return V(x+w.x, y+w.y); }
	V operator-(V w) const { return V(x-w.x, y-w.y); }
	V operator*(T d) const { return V(x*d, y*d); }
	V operator/(T d) const { return V(x/d, y/d); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	T dot(V w) const { return x*w.x + y*w.y; }
  // v cross w
	T cross(V w) const { return x*w.y - y*w.x; }
  // a-v cross b-v
	T cross(V a, V b) const { return (a-*this).cross(b-*this); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
  // unit vector same direction
	V normalize() const { return *this/dist(); } // makes dist()=1
  // rotates +90 deg
	V perp() const { return V(-y, x); }
  // normal vector
	V normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	V rotate(double a) const { return V(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, V v) { return os << "(" << v.x << ", " << v.y << ")"; }
};

struct UF {
  int n; vector<int> A;
  UF (int size) : n(size), A(n) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

typedef vec2<double> vec;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  
  vector<pair<double, pair<int, int>>> E;
  vector<vec> A(n, vec(0, 0)); 
  vector<int> r(n);
  UF uf(n);
  rep (i, 0, n) {
    cin >> A[i].x >> A[i].y >> r[i];
  }

  rep (i, 0, n) {
    rep (j, i+1, n) {
      E.push_back({(A[i] - A[j]).dist() - r[i] - r[j], {i, j}});
    }
  }

  double ans = 0;
  sort(all(E));
  trav (e, E) {
    auto [a, b] = e.snd;
    if (uf.connected(a, b)) continue;
    if (e.fst > 0) ans += e.fst;
    uf.merge(a, b);
  }

  cout << fixed << setprecision(9) << ans << endl;
}

