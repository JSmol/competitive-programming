/*  Random common Number Theory related things
 */

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

ll fexp(ll x, ll p) {
  ll r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x);
    else p >>= 1, x = (x * x);
  }
  return r;
}

ll fexp(ll x, ll p, ll mod) {
  ll r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

// Discrete Log Solver -- O(sqrt(p))
ll discrete_log(ll p, ll b, ll n){
  map<ll, ll> M; ll jump = ceil(sqrt(p));
  for (int i = 0; i < jump and i < p; i++) M[fexp(b, i, p)] = i+1;
  for (int i = 0; i < p-1; i += jump) {
    ll x = (n*fexp(b, p-i-1, p)) % p;
    if (M.find(x) != M.end()) return (i+M[x]-1) % (p-1);
  }
  return -1;
}

set<pair<ll, ll>> factor(ll n) {
  set<pair<ll, ll>> S; ll m = n;
  for (ll i = 2, a = 0; i*i <= n; i++) {
    while (m % i == 0) m /= i, a++;
    if (a > 0) S.insert({i, a}), a = 0;
  }
  if (m > 1) S.insert({m, 1});
  return S;
}

set<ll> divisors(ll n) {
  set<ll> S;
  for (ll i = 1; i*i <= n; i++)
    if (n % i == 0) 
      S.insert(i), S.insert(n/i);
  return S;
}

ll phi(ll n) {
  ll ans = 1;
  set<pair<ll, ll>> S = factor(n);
  for (auto& s : S) ans *= (fexp(s.fst, s.snd) - fexp(s.fst, s.snd-1));
  return ans;
}

ll crt(vector<ll>& A, vector<ll>& M, ll n) {
  ll m = accumulate(all(M), 1ll, multiplies<ll>());
  ll x = 0;
  for (ll i = 0; i < n; i++) {
    ll k = m/M[i];
    ll d = egcd(M[i], k % M[i]).snd;
    x += A[i] * k * d % m;
    x += m;
  }
  return x % m;
}

