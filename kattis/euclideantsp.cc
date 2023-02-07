#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
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

int n;
long double p, s, v;
const long double eps = pow(10, -8);

long double f(long double c) {
  return n*(pow(log2(n), c*sqrt(2)))/(pow(10,9)*p) + (1+1/c)*(s/v);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> p >> s >> v;

  long double l = 0, r = 100;
  while (r - l > eps) {
    long double m1 = l+(r-l)/3.0;
    long double m2 = l+2*((r-l)/3.0);
    if (f(m1) < f(m2))
      r = m2;
    else
      l = m1;
  }

  cout << setprecision(18) << f(l) << ' ' << l << endl;
}

