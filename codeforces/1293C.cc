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

void update(auto& A, auto& st, auto n, auto r, auto c) {
  A[r][c] ^= 1;

  if ((c - 1 >= 0 and A[r][c-1] and A[r][c]) 
   or (c - 1 >= 0 and A[r^1][c-1] and A[r^1][c])) 
    st.update(c-1, 1);
  else if (c-1 >= 0) st.update(c-1, 0);

  if ((c + 1 < n and A[r][c+1] and A[r][c]) 
   or (c + 1 < n and A[r^1][c+1] and A[r^1][c]))
    st.update(c, 1);
  else if (c + 1 < n) st.update(c, 0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<vector<int>> A(2, vector<int>(n, 1));
  segment<int> st(n-1, 1, [] (int a, int b) { return a & b; });
  while (q--) {
    int r, c; cin >> r >> c; r--; c--;
    update(A, st, n, r, c);
    cout << (st.query(0, n-1) ? "Yes" : "No") << endl;
  }
}

