#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

#define double long double
const double pi = acos(-1);
const double eps = 1e-9;

int k;
double w, l;
bool f(double b) {
  int c = 1;
  double h = (w / 2.0) * tan(b);
  b = atan(2.0 * tan(b));
  while (c < k) {
    h += w * tan(b);
    b = atan(2.0 * tan(b));
    c++;
  }

  if (h > l) return 1;
  else {
    b = pi / 2.0 - b;
    return tan(b) < (w / 2.0) / (l - h);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> k >> w >> l;

  double lo = 0.0;
  double hi = pi / 2.0;
  while (hi - lo > eps) {
    double m = (lo + hi) / 2.0;
    if (f(m)) hi = m;
    else lo = m;
  }

  cout << fixed << setprecision(9) << (lo / pi) * 180.0 << endl;
}

