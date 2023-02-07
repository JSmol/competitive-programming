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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;

ll f(ll n, ll m, ll a) {
  if (a % n == 0 or a % m == 0) {
    return 1;
  } else {
    if (a < n or a < m) {
      return 2;
    } else {
      for (ll x = 1; x < n; x++)
        if ((a - x*m) > 0 and (a - x*m) % (n - x) == 0) return 2;
      for (ll x = 1; x < m; x++)
        if ((a - x*n) > 0 and (a - x*n) % (m - x) == 0) return 2;
    }
  }
  return 3;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, a;
  cin >> n >> m >> a;
  ll ans = min(f(n, m, a), f(n, m, n*m - a));
  cout << ans << endl;
}

