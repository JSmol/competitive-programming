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

template<typename T>
T bpow(T x, ll n) { return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1); }
template<typename T>
T bpow(T x, ll n, T m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1); }
template<typename T>
T gcd(const T &a, const T &b) { return b == T(0) ? a : gcd(b, a % b); }
template<typename T>
T nck(T n, int r) { T res(1); for (int i = 0; i < r; i++) { res *= (n - T(i)); res /= (i + 1); } return res; }

template<int m>
struct modular {
  ll r;
  modular() : r(0) {}
  modular(ll r) : r(r) { if (abs(r) >= m) r %= m; if (r < 0) r += m; }
  modular inv() const { return bpow(*this, m - 2); }
  modular operator * (const modular &t) const { return (r * t.r) % m; }
  modular operator / (const modular &t) const { return *this * t.inv(); }
  modular operator += (const modular &t) { r += t.r; if (r >= m) r -= m; return *this; }
  modular operator -= (const modular &t) { r -= t.r; if (r < 0) r += m; return *this; }
  modular operator + (const modular &t) const { return modular(*this) += t; }
  modular operator - (const modular &t) const { return modular(*this) -= t; }
  modular operator *= (const modular &t) { return *this = *this * t; }
  modular operator /= (const modular &t) { return *this = *this / t; }
  bool operator == (const modular &t) const { return r == t.r; }
  bool operator != (const modular &t) const { return r != t.r; }
  operator ll() const { return r; }
};

template<int T>
istream& operator << (istream &out, modular<T> &x) {
  return out << x.r;
}

template<int T>
istream& operator >> (istream &in, modular<T> &x) {
  return in >> x.r;
}

const ll p = 998244353;
struct matrix {
  ll mod = p;
  int n; vector<vector<ll>> A;
  matrix(int n, ll v) : n(n), A(n, vector<ll>(n, v)) {}
  matrix(int n) : n(n), A(n, vector<ll>(n, 0)) { for (int i = 0; i < n; i++) A[i][i] = 1; }
  vector<ll>& operator[](int i) { return A[i]; }
  matrix operator*(matrix& left) {
    auto& a = *this;
    auto& b = left;
    matrix r(n, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          r[i][j] += (a[i][k] * b[k][j]) % mod,
          r[i][j] %= mod;
    return r;
  }
  matrix operator^(ll e) {
    auto b = *this;
    matrix r(n);
    while (e > 0) {
      if (e & 1) r = r * b, e--;
      else b = b * b, e /= 2;
    }
    return r;
  }
};

typedef modular<p> mod;

pair<mod, mod> f(ll n, ll ne, ll no) {
  matrix A(2, 0); 
  A[0][0] = A[1][1] = ne;
  A[0][1] = A[1][0] = no;
  A = A^(n-1);
  vector<mod> v = { ne, no };
  vector<mod> ans(2, 0);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      ans[i] += mod(v[j] * mod(A[i][j]));

  return { ans[0], ans[1] };
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, l, r;
  cin >> n >> m >> l >> r;

  mod ne = (r - l + 1) / 2;
  mod no = mod((r - l + 1) - ne);
  if (n == 1 and m == 1) {
    cout << mod(ne+no) << endl;
  }
  
  auto [w0, w1] = f(n, ne, no);
  debug(mp(ne, no));
  debug(mp(w0, w1));

  matrix A(2, 0);
  A[0][0] = A[1][1] = w0;
  A[0][1] = A[1][0] = w1;

  vector<mod> v = { w0, w1 };
  A = A^(m-1);

  for (int i = 0; i < 2; i++) debug(A[i]);
  cerr << endl;
  
  vector<mod> ans(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      ans[i] += mod(v[j] * mod(A[i][j]));

  // debug(v);
  // debug(ans);
  assert(ll(ans[0]) < p);
  if (m*n % 2 == 1) cout << (ans[0] + ans[1]) << endl;
  else cout << ans[0] << endl;
}

