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

/*  O(n sqrt(n)) Bipartite graph matching
 *  match().fst = # matches
 *  match().snd = match details (L to R, -1 means no match)
 */

struct matching {
  int l, r, p; vector<int> M, U, D; vector<vector<int>> A; queue<int> Q;
  matching (int l, int r) : l(l), r(r), D(r+1), A(r) {}
  void add_edge(int u, int v) { A[v].push_back(u); }
  bool bfs() {
    for (int v = 0; v < r; v++) if (!U[v]) D[v] = p, Q.push(v);
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      if (D[v] != D[r]) for (int u : A[v]) if (D[M[u]] < p)
        D[M[u]] = D[v] + 1, Q.push(M[u]);
    }
    return D[r] >= p;
  }
  int dfs(int v) {
    if (v == r) return 1;
    for (int u : A[v]) if (D[M[u]] == D[v] + 1 and dfs(M[u])) 
      return M[u] = v, 1;
    D[v] = D[r]; return 0;
  }
  pair<int, vector<int>> match() {
    int res = 0; M.assign(l, r), U.assign(r+1, 0);
    for (p = 0; bfs(); p = D[r] + 1) for (int v = 0; v < r; v++)
      if (!U[v] and dfs(v)) U[v] = 1, res++;
    replace(all(M), r, -1); return {res, M};
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int C = 1; C <= T; C++) {
    int c, v, d; cin >> c >> d >> v;

    vector<pair<int, int>> A, B;
    for (int i = 0; i < v; i++) {
      char x, y; int a, b; cin >> x >> a >> y >> b;
      if (x == 'C') {
        A.push_back({a, b});
      } else {
        B.push_back({a, b});
      }
    }

    matching m(sz(A), sz(B));
    for (int i = 0; i < sz(A); i++) {
      for (int j = 0; j < sz(B); j++) {
        if (A[i].fst == B[j].snd or A[i].snd == B[j].fst)
          m.add_edge(i, j);
      }
    }
  
    cout << v - m.match().fst << endl;
  }
}

