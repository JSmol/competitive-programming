/*  String Hashing template, usage example at the bottom.
 *  TIPS:
 *  Avoid hash collision by using multiple primes for base and mod.
 *  Use unordered and pre compute exponentials for best run time.
 *  some primes:
 *  1e9+7, 1e9+9, 1e9+13, 7340033, 469762049, 998244353, 1009
 */

typedef long long ll;
template<typename T> // exp
T bpow(T x, ll n) { return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1); }
template<typename T> // expmod
T bpow(T x, ll n, T m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1); }

template<int m>
struct modular {
  ll r; modular() : r(0) {}
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

typedef modular<998244353> mod;
mod b = 1009;

mod h(const string& s) {
  int n = sz(s); mod hs = 0;
  for (int i = 0; i < n; i++) 
    hs += mod(s[i]) * bpow(b, i);
  return hs;
}

unordered_set<ll> hashes = {
  h("abc"),
  h("xyz"),
  h("banana") 
};

