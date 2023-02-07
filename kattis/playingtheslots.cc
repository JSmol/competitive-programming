#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long double ld;
  
struct Vector {
  ld x, y, z;
  Vector(ld xx = 0, ld yy = 0, ld zz = 0) : x(xx), y(yy), z(zz) {}
  Vector(const Vector& p1, const Vector& p2) : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z) {}
  Vector(const Vector& p1, const Vector& p2, ld t) : x(t*p2.x + p1.x), y(t*p2.y + p1.y), z(t*p2.z + p1.z) {}
  ld norm() {
  return sqrt(x*x +  y*y + z*z);
  }
};

ld dot(Vector p1, Vector p2) {
  return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

ld dp2p(Vector p1, Vector p2) {
  return Vector(p1, p2).norm();
}

ld dp2l(Vector p, Vector a, Vector b) {
  Vector u(a, p), v(a, b); ld s = dot(u, v) / dot(v, v);
  return dp2p(Vector(a, v, s), p);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  vector<Vector> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].x >> A[i].y;
  }

  ld ans = 1 << 30;
  for (int i = 0; i < n; i++) {
    ld diam = 0.0;
    for (int j = 0; j < n; j++) {
      diam = max(diam, dp2l(A[j], A[i], A[(i+1) % n]));
    }

    ans = min(ans, diam);
  }

  cout << ans << endl;
}

