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

typedef long long ll;
template<typename T>
T bpow(T x, ll n) { return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1); }
template<typename T>
T gcd(const T &a, const T &b) { return b == T(0) ? a : gcd(b, a % b); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n; cin >> n; ll m = n;

  vector<pair<ll, ll>> S;
  for (ll i = 2, a = 0; m > 1 and i*i <= n; i++, a = 0) {
    while (m > 1 and m % i == 0) m /= i, a++;
    if (a > 0) S.push_back({i, a});
  }
  if (m > 1) S.push_back({m, 1});
  debug(S);

  pair<ll, ll> best = {-1, -1};
  for (int i = 0; i < (1<<sz(S)); i++) {
    ll a = 1, b = 1;
    for (int j = 0; j < sz(S); j++) {
      if (i & (1 << j)) {
        a *= bpow(S[j].fst, S[j].snd);
      } else {
        b *= bpow(S[j].fst, S[j].snd);
      }
    }

    if (best == mp(-1ll, -1ll) or max(a, b) < max(best.fst, best.snd)) best = {a, b};
  }

  cout << best.fst << ' ' << best.snd << endl;
}

