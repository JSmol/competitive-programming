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

// example usage...
g.build();
auto D = g.D;
auto dist = [&] (int a, int b) {
  return (D[a] + D[b]) - 2*D[g.lca(a, b)];
};

