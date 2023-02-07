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

/*  LCA queries O(n log(n)) build and queries (binary lifting method);
 *  after calling build(), we have the following information:
 *  A = original adj list
 *  D[i] = depth of vertex i
 *  t[i][j] = 2^j'th parent of i
 */

const int logn = 20;
struct LCA {
  int n; vector<vector<int>> A;
  vector<int> D; vector<vector<int>> t;
  LCA(int n) : n(n), A(n), D(n, -1), t(n, vector<int>(logn, -1)) {}
  void add_edge(int a, int b) { A[a].push_back(b); A[b].push_back(a); }
  void dfs(int v, int p, int d) {
    t[v][0] = p; D[v] = d;
    for (auto& a : A[v]) {
      if (a == p) continue;
      dfs(a, v, d+1);
    }
  }
  void build(int root = 0) {
    dfs(root, -1, 0);
    for (int j = 1; j < logn; j++) {
      for (int i = 0; i < n; i++) {
        if (t[i][j-1] != -1) t[i][j] = t[t[i][j-1]][j-1];
      }
    }
  }
  int lca(int a, int b) {
    if (D[a] > D[b]) swap(a, b);
    for (int j = logn-1; j >= 0; j--)
      if (t[b][j] != -1 and D[a] <= D[t[b][j]]) 
        b = t[b][j];
    if (a == b) return a;
    for (int j = logn-1; j >= 0; j--)
      if (t[b][j] != t[a][j])
        b = t[b][j], a = t[a][j];
    return t[a][0];
  };
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;

  LCA g(n);
  for (int i = 0, a, b; i < n-1; i++) {
    cin >> a >> b; a--; b--;
    g.add_edge(a, b);
  }

  g.build(0);
  auto D = g.D;
  auto dist = [&] (int a, int b) {
    return (D[a] + D[b]) - 2*D[g.lca(a, b)];
  };
  
  for (int i = 0, k; i < m; i++) {
    cin >> k;
    vector<int> a(k);
    for (auto& x : a) cin >> x, x--;

    sort(rall(a), [&] (int a, int b) { return D[a] < D[b]; });

    int p = 1;
    for (int i = 0; i+1 < k; i++) {
      int c = g.lca(a[i], a[i+1]);
      if (c == a[i] or c == a[i+1]) continue;
      if (dist(c, a[i]) == 1 or dist(c, a[i+1]) == 1) continue;
      p = 0;
    }
    cout << (p ? "YES" : "NO") << endl;
  }
}

