#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

typedef long long ll;

ll fexp(ll x, ll p, ll mod) {
  ll r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

const ll p1 = 1e9+9;
const ll p2 = 1e9+7;
const ll b = 1009;
ll hs1(set<pair<ll, ll>>& S) {
  ll ans = 0;
  for (auto& s : S) {
    ans += fexp(b, s.fst, p1) * s.snd;
    ans %= p1;
  }
  return ans % p1;
}

ll hs2(set<pair<ll, ll>>& S) {
  ll ans = 0;
  for (auto& s : S) {
    ans += fexp(b, s.fst, p2) * s.snd;
    ans %= p2;
  }
  return ans % p2;
}

set<pair<ll, ll>> factor(ll n, ll k) {
  set<pair<ll, ll>> S;
  for (ll i = 2, a = 0; i*i <= n; i++) {
    while (n % i == 0) n /= i, a++;
    if (a > 0) S.insert({i, a%k}), a = 0;
  }

  if (n > 1) S.insert({n, 1});
  return S;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  vector<int> A(n);
  for (auto& a : A) cin >> a;

  ll ans = 0;
  map<pair<ll, ll>, ll> H;
  for (int i = 0; i < n; i++) {
    auto S = factor(A[i], k);
    set<pair<ll, ll>> T;
    for (auto& s : S) {
      T.insert({s.fst, (k-s.snd) % k});
    }

    ans += H[{hs1(T), hs2(T)}];
    H[{hs1(S), hs2(S)}]++;

    // debug(A[i]);
    // debug(S);
    // debug(hs(S));
    // debug(T);
    // debug(hs(T));
    // debug(ans);
    // cerr << endl;
  }

  cout << ans << endl;
}

