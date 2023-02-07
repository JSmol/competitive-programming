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

typedef long long ll;

set<ll> divisors(ll n) {
  set<ll> S;
  for (ll i = 1; i*i <= n; i++)
    if (n % i == 0) 
      S.insert(i), S.insert(n/i);
  return S;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  vector<int> X(n), Y(m), A, B;
  for (auto& a : X) cin >> a;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i + 1;
    if (X[i] == 1) {
      while (j < n and X[j] == 1) j++;
      A.push_back(j-i);
    }
  }

  for (auto& b : Y) cin >> b;
  for (int i = 0, j = 0; i < m; i = j) {
    j = i + 1;
    if (Y[i] == 1) {
      while (j < m and Y[j] == 1) j++;
      B.push_back(j-i);
    }
  }

  n = sz(A);
  m = sz(B);
  ll ans = 0;
  auto S = divisors(k);
  for (auto& x : S) {
    ll y = k / x;
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) a += max(0ll, A[i] - x + 1);
    for (int i = 0; i < m; i++) b += max(0ll, B[i] - y + 1);
    ans += a * b;
  }

  cout << ans << endl;
}

