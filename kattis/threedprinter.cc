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


const double PI = acos(-1.0), EPS = 1e-8;

struct Vector {
  double x, y, z;
  Vector(double xx = 0, double yy = 0, double zz = 0) : x(xx), y(yy), z(zz) { }
  Vector(const Vector &p1, const Vector &p2)
    : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z) { }
  Vector(const Vector &p1, const Vector &p2, double t)
    : x(p1.x + t*p2.x), y(p1.y + t*p2.y), z(p1.z + t*p2.z) { }
  double norm() const { return sqrt(x*x + y*y + z*z); }
  bool operator==(const Vector&p) const{
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS && abs(z - p.z) < EPS;
  }
};

double dot(Vector p1, Vector p2) { return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z; }
double angle(Vector p1,Vector p2) {  return acos(dot(p1, p2)/p1.norm()/p2.norm()); }
Vector cross(Vector p1, Vector p2) { return Vector(p1.y*p2.z-p2.y*p1.z, p2.x*p1.z-p1.x*p2.z, p1.x*p2.y-p2.x*p1.y); }
Vector operator+(Vector p1,Vector p2){ return Vector(p1.x+p2.x,p1.y+p2.y,p1.z+p2.z); }
Vector operator-(Vector p1,Vector p2){ return Vector(p1.x-p2.x,p1.y-p2.y,p1.z-p2.z); }
Vector operator*(double c,Vector v){ return Vector(c*v.x, c*v.y, c*v.z); }

typedef tuple<Vector,Vector,Vector> tvvv;
double volume_polyhedron(vector<tvvv>& p){
  Vector c,p0,p1,p2; double v, volume = 0;
  for(int i=0;i<p.size();i++)
    c = c + get<0>(p[i]) + get<1>(p[i]) + get<2>(p[i]);
  c = 1/(3.0*p.size())*c;
  for(int i=0;i<p.size();i++){
    tie(p0,p1,p2) = p[i], v = dot(p0,cross(p1,p2)) / 6;
    if(dot(cross(p2-p1,p0-p1),c-p0) > 0) volume -= v;
    else volume += v;
  }
  return volume;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    vector<tvvv> X;
    int f; cin >> f;
    for (int j = 0; j < f; j++) {
      int v; cin >> v;
      vector<Vector> A;
      for (int k = 0; k < v; k++) {
        double x, y, z; cin >> x >> y >> z;
        A.push_back(Vector(x, y, z));
      }

      for (int k = 1; k+1 < v; k++) {
        X.push_back({A[0], A[k], A[k+1]});
      }
    }

    ans += volume_polyhedron(X);
  }
  
  cout << fixed << setprecision(2) << ans << endl;

}

