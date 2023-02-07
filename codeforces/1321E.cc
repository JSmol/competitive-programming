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
  id(id), op(op), L(1 << (d+1), 0), R(1 << (d+1), 0), D(1 << (d+1), 0), S(1 << (d+1), id) {
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

const int N = 1 << 20;
const ll inf = 1ll << 58;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, p; cin >> n >> m >> p; 
  vector<pair<ll, ll>> A(n), B(m); ll a = inf, b = inf;
  for (auto& x : A) cin >> x.fst >> x.snd, a = min(a, x.snd);
  for (auto& x : B) cin >> x.fst >> x.snd, b = min(b, x.snd);
  vector<pair<pair<ll, ll>, int>> X(p);
  for (auto& [x, y] : X) cin >> x.fst >> x.snd >> y;
  sort(all(A)); sort(all(B)); sort(all(X));

  vector<int> I(p); iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return X[i].fst.snd < X[j].fst.snd; });

  vector<int> J(p);
  for (int i = 0; i < p; i++) J[I[i]] = i;

  vector<ll> O(p);
  for (ll i = p-1, j = m-1, b = inf; ~i; --i) {
    while (~j and X[I[i]].fst.snd < B[j].fst) b = min(b, B[j--].snd);
    O[i] = -b;
  }

  ll ans = -(a + b);
  segment<ll> st(N, -inf, [] (ll a, ll b) { return max(a, b); }, O);
  for (int i = 0, j = 0; i < n; i++) {
    while (j < p and X[j].fst.fst < A[i].fst) {
      st.update(J[j], N-1, X[j].snd);
      j++;
    }

    ans = max(ans, st.query(0, N-1) - A[i].snd);
  }

  cout << ans << endl;
}

