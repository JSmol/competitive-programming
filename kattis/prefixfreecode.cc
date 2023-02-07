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
const ll p = 1e9+7;
const ll b = 1e3+9;
const ll c = 1e3+13;

// add(i, v) = add v to A[i] | i in [1, n]
// query(i) = range sum [1, i]
struct fenwick {
  int n; vector<int> A;
  fenwick(int n) : n(n+1), A(n+1) { }
  void add(int i, int v) { while (i < n) A[i] += v, i += i & -i; } 
  int query(int i) { int s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
};

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

ll fexp(ll x, ll p, ll mod) {
  ll r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

pair<ll, ll> hs(string s) {
  ll h = 0, l = 0;
  for (int i = 0; i < sz(s); i++) {
    h += (s[i] - 'a' + 1) * fexp(b, i, p);
    h %= p;
    l += (s[i] - 'a' + 1) * fexp(c, i, p);
    l %= p;
  }
  return {h, l};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  vector<ll> X(n+1, 1);
  for (int i = 1; i <= n; i++) X[i] = (i * X[i-1]) % p;

  vector<string> A(n);
  for (auto& a : A) cin >> a;

  sort(all(A));
  map<pair<ll, ll>, int> M;
  for (int i = 0; i < n; i++) M[hs(A[i])] = i;

  string s;
  cin >> s;
  ll ans = 0;
  fenwick f(n);
  for (int i = 1; i <= n; i++) f.add(i, 1);

  for (int i = 0, j = 0; i < sz(s); i += j) {
    ll h = 0, l = 0; j = 0;
    while (!M.count({h, l})) {
      h += (s[i+j] - 'a' + 1) * fexp(b, j, p); 
      h %= p; 
      l += (s[i+j] - 'a' + 1) * fexp(c, j, p); 
      l %= p; 
      j++;
    }
    pair<ll, ll> x = {h, l};
    f.add(M[x]+1, -1);

    ans += ((f.query(M[x]) * X[f.query(n)]) % p) * modinv(X[n - k], p);
    ans %= p;
  }

  cout << (ans + 1) % p << endl;
}

