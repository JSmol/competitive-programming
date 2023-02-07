#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define emplace emplace_back

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
  void update(int x) {
    for (S[x += n].fst += 1; x > 1; x /= 2) 
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
  int q, x; cin >> q >> x;
  vector<pair<int, int>> C(x);
  for (int i = 0; i < x; i++) C[i].snd = i;
  segment<pair<int, int>> s(x, { 1<<30, 1<<30 }, [] (pair<int, int> a, pair<int, int> b) { return min(a, b); }, C);
  for (int i = 0, a; i < q; i++) {
    cin >> a;
    C[a % x].fst++;
    s.update(a % x);
    auto res = s.query(0, x);
    int ans = res.fst * x + res.snd;
    cout << ans << endl;
  }
}

