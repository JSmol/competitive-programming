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

typedef long double ld;
typedef long long ll;

struct fraction {
  ll n, d;
  fraction(ll a, ll b) : n(a), d(b) {}
  bool operator<(const fraction& f) const {
    ll l = (d * f.d) / __gcd(d, f.d);
    return (n*(d/l)) < (f.n*(f.d/l));
  }
  bool operator==(const fraction& f) const {
    return n == f.n and d == f.d;
  }
};

ostream& operator<<(ostream& o, const fraction f) {
  o << '(' << f.n << '/' << f.d << ')'; return o;
}

int n;
vector<ll> A;
vector<ld> F, B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  F.assign(n, 0);
  for (ll i = 0, s = 0; i < n; i++) {
    s += A[i];
    F[i] = (ld) s / (ld) (i+1);
  }

  B.assign(n, 0);
  for (ll i = 0, s = 0; i < n; i++) {
    s += A[n-1-i];
    B[n-1-i] = (ld) s / (ld) (i+1);
  }

  ld ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max({ans, F[i], B[i]});
  }

  cout << setprecision(9) << fixed << ans << endl;
}

