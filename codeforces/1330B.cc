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
  // set A[x] to v
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
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, x--;

    vector<int> c(n);
    segment<int> ts(n, 0, [] (int a, int b) { return a + b; });
    for (int i = 0; i < n; i++) { 
      ts.update(a[i], 1);
      c[a[i]]++;
    }

    vector<pair<int, int>> ans;
    segment<int> st(n, 0, [] (int a, int b) { return a + b; });
    for (int i = 0; i < n; i++) {

      st.update(a[i], 1);

      c[a[i]]--;
      if (c[a[i]] == 0) ts.update(a[i], 0);

      if (st.query(0, i+1) == i+1 and ts.query(0, n-i-1) == n-i-1) {
        ans.push_back({i+1, n-i-1});
      }
    }

    cout << sz(ans) << endl;
    for (auto& x : ans) cout << x.fst << ' ' << x.snd << endl;
  }
}

