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

template<typename T>
struct segment {
  int n; T id; function<T(T, T)> op;
  vector<T> S;
  // initialize tree with size n, op: (T, T) -> (T), identity value and optional initial data.
  segment(int n, T id, function<T(T, T)> op, const vector<T>& A = {}) 
    : n(n), id(id), op(op), S(2*n, id) {
    for (int i = 0; i < sz(A); i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }
  // set v to A[x]
  void update(int x, T v) {
    for (S[x += n] = v; x > 1; x /= 2) 
      S[x/2] = op(S[x], S[x^1]);
  }
  // query range op(A[l], ... , A[r-1]).
  T query(int l, int r) {
    T ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a, a--;
  
  vector<vector<int>> X(n);
  vector<int> prev(n, -1);
  for (int i = 0; i < n; i++) {
    if (sz(X[A[i]]) > 0) prev[i] = X[A[i]].back();
    X[A[i]].push_back(i);
  }

  vector<int> f(n, -1), l(n, -1);
  for (int i = 0; i < n; i++) {
    if (sz(X[i]) > 0) f[i] = X[i][0], l[i] = X[i].back();
  }

  const int inf = 1 << 30;
  segment<pair<int, int>> s(n, {inf, inf}, [] (pair<int, int> a, pair<int, int> b) { 
    vector<int> T = { a.fst, a.snd, b.fst, b.snd }; sort(all(T));
    return mp(T[0], T[1]);
  });

  int a = inf, b = inf;
  for (int i = 0; i < n; i++) {
    pair<int, int> r = s.query(f[A[i]], i);
    if (r.fst < inf and r.fst != A[i]) {
      if (A[i] < a or (A[i] == a and r.fst < b)) 
        a = A[i], b = r.fst;
    }

    if (r.snd < inf and r.snd != A[i]) {
      if (A[i] < a or (A[i] == a and r.snd < b)) 
        a = A[i], b = r.snd;
    }

    if (i != l[A[i]]) s.update(i, {A[i], inf});
    if (prev[i] >= 0) s.update(prev[i], {inf, inf});
  }

  if (a < inf and b < inf) cout << a+1 << ' ' << b+1 << endl;
  else cout << -1 << endl;
}

