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
pair<ll, ll> egcd(ll a, ll b) {
  if (b > a) swap(a, b);
  ll s = 0, t = 1, u = 1, v = 0, q = 0;
  while (b != 0) {
    q = a/b; swap(a, b);
    b = b % a; swap(s, u);
    s = s - u * q; swap(t, v);
    t = t - v * q;
  }
  return {u, v};
}

ll modinv(ll a, ll m) { return (egcd(a, m).snd + m) % m; }

/*  number theoretic transform.
 *  pick prime p such that 
 *  p = c * 2^k + 1, then
 *  ord = 2^k, and
 *  r = g^c, where g is a primitive root
 *  common values: p, r, ord.
 *  7340033, 5, 1 << 20
 *  469762049, 13, 1 << 25
 *  998244353, 31, 1 << 23
 *  1107296257, 8, 1 << 24
 *  ... need __int128 for these
 *  10000093151233, 366508, 1 << 26
 *  1000000523862017, 2127080, 1 << 26
 *  To find solution mod arbitrary modulus, use CRT
 *  ! watch for 64 bit int overflow
 */

struct ntconv {
  ll p, r, rinv, ord;
  ntconv(ll p, ll r, ll ord) : p(p), r(r), rinv(modinv(r, p)), ord(ord) {}
  void ntt(vector<ll>& A, bool inv) {
    ll n = sz(A);
    for (ll i = 1, j = 0; i < n; i++) {
      ll b = n >> 1;
      for (; j & b; b >>= 1) j ^= b;
      j ^= b; if (i < j) swap(A[i], A[j]);
    }
    for (ll l = 2; l <= n; l <<= 1) {
      ll wl = inv ? rinv : r;
      for (ll i = l; i < ord; i <<= 1) wl = wl * wl % p;
      for (ll i = 0; i < n; i += l) {
        ll w = 1;
        for (ll j = 0; j < l/2; j++) {
          ll u = A[i+j], v = A[i+j+l/2] * w % p;
          A[i+j] = u + v < p ? u + v : u + v - p;
          A[i+j+l/2] = u - v >= 0 ? u - v : u - v + p;
          w = w * wl % p;
        }
      }
    }
    if (inv) {
      ll ninv = modinv(n, p);
      for (auto& a : A) a = a * ninv % p;
    }
  }
  vector<ll> mult(vector<ll> A, vector<ll> B) {
    int n = sz(A), m = sz(B), N = 1;
    while (N < n + m) N <<= 1;
    A.resize(N); B.resize(N);
    ntt(A, 0); ntt(B, 0); vector<ll> ans(N);
    for (int i = 0; i < N; i++) ans[i] = A[i] * B[i] % p;
    ntt(ans, 1);
    return ans;
  }
};

const ll N = 1 << 23;
const ll p = 998244353;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = sz(s);
  vector<ll> a(2*n), b(2*n);
  for (int i = 0; i < n; i++) {
    a[i] = (s[i] == 'A');
    b[n-i] = (s[i] == 'B');
  }
  
  ntconv nt(p, 31, N);
  auto x = nt.mult(a, b);
  for (int i = 1; i < n; i++)
    cout << x[n+i] << '\n';
}

