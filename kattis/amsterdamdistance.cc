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
double arclen(double r, double a) {
  return a * r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  double m, n, r;
  cin >> m >> n >> r;

  double a, b, c, d;
  cin >> a >> b >> c >> d;

  double ans = 1<<30;
  double theta = pi / m * abs(a - c);
  for (int i = 0; i <= n; i++) {
    ans = min(ans, arclen(i * r / n, theta) + abs(b-i) * r / n + abs(d-i) * r / n);
  }

  cout << fixed << setprecision(9) << ans << endl;
}

