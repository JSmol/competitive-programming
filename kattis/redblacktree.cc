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

namespace algebra {

  #define double long double
  typedef double ftype;
  typedef long long ll;
  typedef complex<ftype> point;
  const double pi = acos(-1);
  const int maxn = 1 << 18;
  const int inf = 1<<30;

  point w[maxn];
  bool initiated = 0;
  void init() {
    if (!initiated) {
      for(int i = 1; i < maxn; i *= 2)
        for(int j = 0; j < i; j++)
          w[i + j] = polar(ftype(1), pi * j / i);
      initiated = 1;
    }
  }

  template<typename T>
  void fft(T *in, point *out, int n, int k = 1) {
    if (n == 1) {
      *out = *in;
    } else {
      n /= 2;
      fft(in, out, n, 2 * k);
      fft(in + k, out + n, n, 2 * k);
      for (int i = 0; i < n; i++) {
        auto t = out[i + n] * w[i + n];
        out[i + n] = out[i] - t;
        out[i] += t;
      }
    }
  }

  template<typename T>
  void slow(vector<T> &a, const vector<T> &b) {
    vector<T> res(max(sz(a) + sz(b) - 1, 0));
    for (int i = 0; i < sz(a); i++) {
      for (int j = 0; j < sz(b); j++) {
        res[i + j] += a[i] * b[j];
      }
    }
    a = res;
  }


  template<typename T>
  void mult(vector<T> &a, const vector<T> &b) {
    if (min(sz(a), sz(b)) < 1010) { slow(a, b); return; }
    init();
    static const int shift = 15, mask = (1 << shift) - 1;
    int n = sz(a) + sz(b) - 1;
    while (__builtin_popcount(n) != 1) n++;
    a.resize(n);
    static point A[maxn], B[maxn], C[maxn], D[maxn];
    for (int i = 0; i < n; i++) {
      A[i] = point(a[i] & mask, a[i] >> shift);
      if (i < sz(b)) B[i] = point(b[i] & mask, b[i] >> shift);
      else B[i] = 0;
    }
    fft(A, C, n); fft(B, D, n);
    for (int i = 0; i < n; i++) {
      point c0 = C[i] + conj(C[(n - i) % n]);
      point c1 = C[i] - conj(C[(n - i) % n]);
      point d0 = D[i] + conj(D[(n - i) % n]);
      point d1 = D[i] - conj(D[(n - i) % n]);
      A[i] = c0 * d0 - point(0, 1) * c1 * d1;
      B[i] = c0 * d1 + d0 * c1;
    }
    fft(A, C, n); fft(B, D, n);
    reverse(C + 1, C + n); reverse(D + 1, D + n);
    int t = 4 * n;
    for (int i = 0; i < n; i++) {
      ll A0 = llround(real(C[i]) / t);
      T A1 = llround(imag(D[i]) / t);
      T A2 = llround(imag(C[i]) / t);
      a[i] = A0 + (A1 << shift) + (A2 << 2 * shift);
    }
  }

  template<typename T>
	T bpow(T x, ll n) { return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1); }
	template<typename T>
	T bpow(T x, ll n, T m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1); }
	template<typename T>
	T gcd(const T &a, const T &b) { return b == T(0) ? a : gcd(b, a % b); }
	template<typename T>
	T nCr(T n, int r) { T res(1); for (int i = 0; i < r; i++) { res *= (n - T(i)); res /= (i + 1); } return res; }

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

  template<typename T>
  struct poly {
    vector<T> a;
    poly() {}
    poly(T a0) : a{a0} { normalize(); }
    poly(vector<T> t) : a(t) { normalize(); }
    void normalize() { while (!a.empty() && a.back() == T(0)) a.pop_back(); }

    poly operator += (const poly &t) {
      a.resize(max(sz(a), sz(t.a)));
      for (int i = 0; i < sz(t.a); i++) a[i] += t.a[i];
      normalize();return *this;
    }
    poly operator -= (const poly &t) { 
      a.resize(max(sz(a), sz(t.a))); 
      for (int i = 0; i < sz(a); i++) a[i] -= t.a[i];
      normalize(); return *this; 
    }
    poly operator + (const poly &t) const { return poly(*this) += t; }
    poly operator - (const poly &t) const { return poly(*this) -= t; }
    poly operator *= (const poly &t) { mult(a, t.a); normalize(); return *this; }
    poly operator * (const poly &t) const { return poly(*this) *= t; }

    // for division and remainder
    poly mod_xk(int k) const { k = min(k, sz(a)); return vector<T>(begin(a), begin(a) + k); }
    poly mul_xk(int k) const { poly res(*this); res.a.insert(begin(res.a), k, 0); return res; }
    poly div_xk(int k) const { k = min(k, sz(a)); return vector<T>(begin(a) + k, end(a)); }
    poly substr(int l, int r) const { l = min(l, sz(a)); r = min(r, sz(a)); return vector<T>(begin(a) + l, begin(a) + r); }
    poly inv(int n) const { // get inverse series mod x^n
      assert(!is_zero()); poly ans = a[0].inv(); int a = 1;
      while (a < n) { poly C = (ans * mod_xk(2 * a)).substr(a, 2 * a); ans -= (ans * C).mod_xk(a).mul_xk(a); a *= 2; }
      return ans.mod_xk(n);
    }
    poly reverse(int n, bool rev = 0) const {
      poly res(*this);
      if (rev) res.a.resize(max(n, sz(res.a)));
      std::reverse(all(res.a)); return res.mod_xk(n);
    }
    pair<poly, poly> divmod(const poly &b) const {
      if (deg() < b.deg()) return {poly{0}, *this};
      int d = deg() - b.deg();
      poly D = (reverse(d + 1) * b.reverse(d + 1).inv(d + 1)).mod_xk(d + 1).reverse(d + 1, 1);
      return {D, *this - D * b};
    }
    poly operator /= (const poly &t) { return *this = divmod(t).first; }
    poly operator %= (const poly &t) { return *this = divmod(t).second; }
    poly operator / (const poly &t) const { return divmod(t).first; }
    poly operator % (const poly &t) const { return divmod(t).second; }
    poly operator *= (const T &x) { for (auto &it: a) it *= x; normalize(); return *this; }
    poly operator /= (const T &x) { for (auto &it: a) it /= x; normalize(); return *this; }
    poly operator * (const T &x) const { return poly(*this) *= x; }
    poly operator / (const T &x) const { return poly(*this) /= x; }

    T eval(T x) const { T res(0); for (int i = sz(a) - 1; i >= 0; i--) res *= x, res += a[i]; return res; }
    T& lead() { return a.back(); }
    int deg() const { return a.empty() ? -inf : sz(a) - 1; }
    bool is_zero() const { return a.empty(); }
    T operator [](int idx) const { return idx >= sz(a) || idx < 0 ? T(0) : a[idx]; }
    T& coef(int idx) { return a[idx]; }
    bool operator == (const poly &t) const { return a == t.a; }
    bool operator != (const poly &t) const { return a != t.a; }
    poly deriv() { vector<T> res; for (int i = 1; i <= deg(); i++) res.push_back(T(i) * a[i]); return res; }
    poly integr() { vector<T> res = {0}; for (int i = 0; i <= deg(); i++) res.push_back(a[i] / T(i + 1)); return res; }
    int leading_xk() const { if (is_zero()) return inf; int res = 0; while (a[res] == T(0)) res++; return res; }

    template<typename iter>
    vector<T> eval(vector<poly> &tree, int v, iter l, iter r) {
      if (r - l == 1) {
        return {eval(*l)};
      } else {
        auto m = l + (r - l) / 2;
        auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
        auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
        A.insert(end(A), begin(B), end(B));
        return A;
      }
    }

    // evaluate polynomial in (x1, ..., xn)
    vector<T> eval(vector<T> x) {
      int n = sz(x);
      if (is_zero()) return vector<T>(n, T(0));
      vector<poly> tree(4 * n);
      build(tree, 1, all(x));
      return eval(tree, 1, all(x));
    }

    template<typename iter>
    poly inter(vector<poly> &tree, int v, iter l, iter r, iter ly, iter ry) {
      if (r - l == 1) {
        return {*ly / a[0]};
      } else {
        auto m = l + (r - l) / 2;
        auto my = ly + (ry - ly) / 2;
        auto A = (*this % tree[2 * v]).inter(tree, 2 * v, l, m, ly, my);
        auto B = (*this % tree[2 * v + 1]).inter(tree, 2 * v + 1, m, r, my, ry);
        return A * tree[2 * v + 1] + B * tree[2 * v];
      }
    }
  };

  template<typename T, typename iter>
  poly<T> build(vector<poly<T>> &res, int v, iter L, iter R) {
    if (R - L == 1) {
      return res[v] = vector<T>{-*L, 1};
    } else {
      iter M = L + (R - L) / 2;
      return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
    }
  }

  // interpolates minimum polynomial from (xi, yi) pairs
  template<typename T>
  poly<T> inter(vector<T> x, vector<T> y) {
    int n = sz(x); vector<poly<T>> tree(4 * n);
    return build(tree, 1, all(x)).deriv().inter(tree, 1, all(x), all(y));
  }

};

using namespace algebra;
const ll p = 1e9+7;
typedef modular<p> b;

int n, m;
vector<int> X;
vector<vector<int>> A;

poly<b> f(int v) {
  if (!sz(A[v])) return (X[v] ? poly<b>({1, 1}) : poly<b>(2));
  poly<b> g(1);
  for (auto& a : A[v]) g *= f(a);
  return g + (X[v] ? poly<b>({0, 1}) : poly<b>(1));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, {});
  for (int i = 1, x; i < n; i++) {
    cin >> x; x--;
    A[x].push_back(i);
  }

  X.assign(n, 0);
  for (int i = 0, x; i < m; i++) cin >> x, x--, X[x] = 1;

  auto g = f(0);
  for (int i = 0; i <= m; i++) {
    if (i <= g.deg()) cout << g[i] << endl;
    else cout << 0 << endl;
  }
}

