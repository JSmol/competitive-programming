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

// segment tree with lazy prop, log(n) range query and range update.
// st.update(l, r, v) -> apply(i, v) where i ranges in [l, r]
// st.query(l, r) -> compute op of range [l, r]
// think about non-commutative ops!!

template<typename T>
struct segment {

  // these will work for min/max query and range add.
  // most other ops will require modification here.
  // (default to add v)
  void apply(int i, T v) {
    S[i] += v;
    D[i] += v;
  }

  void prop(int i) {
    if (depth(i) != d and D[i]) {
      apply(2*i+1, D[i]);
      apply(2*i, D[i]);
      D[i] = 0;
    }
  }

  // initialize tree with size n, op: (T, T) -> (T), identity value and optional initial data.
  int n, d; T id; function<T(T, T)>op; 
  vector<int> L, R; vector<T> D, S;
  int depth(int i) { return 31 - __builtin_clz(i); }
  segment(int n, T id, function<T(T, T)> op, const vector<T>& A = {}) : n(n), d(depth(n) + (n != 1 << depth(n))), 
  id(id), op(op), L(1 << (d+1), 0), R(1 << (d+1), 0), D(1 << (d+1), 0), S(1 << (d+1), 0) {
    for (int i = 0; i <= d; i++)
      for (int j = (1 << i); j < (1 << (i+1)); j++)
        L[j] = (j % (1 << i)) * (1 << (d - i)),
        R[j] = L[j] + (1 << (d - i)) - 1;
    for (int i = 0; i < sz(A); i++) S[(1<<d)+i] = A[i];
    for (int i = (1 << d) - 1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  // update range [l, r]
  void update(int l, int r, T v, int i = 1) {
    if (r < l) return;
    if (L[i] == l and R[i] == r) apply(i, v);
    else {
      prop(i);
      update(l, min(r, R[2*i]), v, 2*i); 
      update(max(l, L[2*i+1]), r, v, 2*i+1);
      S[i] = op(S[2*i], S[2*i+1]);
    }
  }

  // query op in range [l, r]
  T query(int l, int r, int i = 1) {
    if (r < l) return id;
    if (L[i] == l and R[i] == r) return S[i];
    else {
      prop(i);
      return op(query(l, min(r, R[2*i]), 2*i), query(max(l, L[2*i+1]), r, 2*i+1));
    }
  }
};

typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < (n+1)/2; i++) {
    cin >> a[i];
  }

  ll x; cin >> x;
  for (int i = (n+1)/2; i < n; i++) {
    a[i] = x;
  }

  if (accumulate(all(a), 0ll) > 0) {
    cout << n << endl;
    return 0;
  }

  segment<ll> st(1 << 20, (1ll << 62), [] (ll a, ll b) { return min(a, b); });
  st.update(0, 0, accumulate(all(a), 0ll));
  for (int k = n-1; k >= (n+1)/2; k--) {
    st.update(n-k, n-k, st.query(n-k-1, n-k-1) - a[n-k-1]);
    st.update(0, n-k-1, -x);

    if (st.query(0, n-k) > 0) {
      cout << k << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}

