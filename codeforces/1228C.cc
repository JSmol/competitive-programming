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
const ll mod = 1e9+7;

ll fexp(ll m, ll p) {
  ll r = 1; ll x = m;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x, n;
  cin >> x >> n;

  set<ll> S;
  for (ll i = 2; i*i <= x; i++) {
    ll a = 0;
    while (x % i == 0) a++, x /= i;
    if (a > 0) S.insert(i);
  }

  if (x > 1) S.insert(x);

  ll ans = 1;
  for (ll s : S) {
    ll m = n;
    while (m > 0) {
      ans = (ans * fexp(s, m/s)) % mod;
      m /= s;
    }
  }

  cout << ans << endl;
}

