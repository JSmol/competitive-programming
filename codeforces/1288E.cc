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

// add(i, v) = add v to A[i] | i in [1, n]
// query(i) = range sum [1, i]
// lower_bound(x) = i such that query(i) < x and query(i+1) >= x
struct fenwick {
  int n; vector<int> A;
  fenwick(int n) : n(n+1), A(n+1) { }
  void add(int i, int v) { while (i < n) A[i] += v, i += i & -i; } 
  int query(int i) { int s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
  int lower_bound(int x) {
    int i = 0; // NOTE: A[i] >= 0. for this to make sense!
    for (int b = 1 << (31 - __builtin_clz(n)); b; b /= 2)
      if (i+b < n and x > A[i+b]) x -=  A[i+b], i += b;
    return i;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;

  map<int, int> M;
  fenwick f(n+m);
  for (int i = 1; i <= n; i++) {
    f.add(m+i, 1);
    M[i] = m+i;
  }

  vector<int> l(n+1), h(n+1);
  iota(all(l), 0), iota(all(h), 0);
  for (int i = 0, x; i < m; i++) {
    cin >> x;
    h[x] = max(h[x], f.query(M[x]));
    f.add(M[x], -1);
    f.add(m-i, 1);
    M[x] = m-i;
    l[x] = 1;
  }

  for (int i = 1; i <= n; i++) {
    cout << l[i] << ' ' << max(h[i], f.query(M[i])) << endl;
  }
}

