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
typedef modular<p> mod;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  if (n == 1) return cout << 10 << endl, 0;

  vector<ll> ans;
  for (int k = 1; k < n; k++) {
    mod x = 0;
    if (n-k-2 >= 0) x += mod(9*9) * mod((n-2)-(k-1)) * bpow(mod(10), n-2-k);
    if (n-k-1 >= 0) x += mod(2*9) * bpow(mod(10), n-k-1);
    ans.push_back(mod(10) * x);
  }

  ans.push_back(10);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
  }
}

