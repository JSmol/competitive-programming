/*  Prefix Trie Datastructure (must call initlca() to use LCA feature)
 *  init with maximum possible number of nodes...
 *  D[lca(a, b)] = length of longest common prefix of strings ending on node a and b.
 */

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int s = 26;
const int logn = 20;
int index(char c) { return (int) alphabet.find(c); }

struct trie {

  int n; vector<vector<int>> A;
  trie(int n) : n(1), A(n, vector<int>(s+1, 0)) { }

  // returns vertex of last char in w (for LCA queries)
  int add(string w, int v) {
    int i = 0, j = 0;
    int l = sz(w);
    while (j < l) {
      int& k = A[i][index(w[j])];
      if (k != 0) i = k, j++;
      else i = k = n++, j++;
    }
    A[i][s] = v;
    return i;
  }

  // returns value of w if it exists
  int find(string w) {
    int i = 0;
    for (auto& l : w){
      int c = index(l);
      i = A[i][c];
      if (!i) return -1;
    }
    return A[i][s];
  }
  
  // --- LCA Query on Trie --- //
  // D[i] = depth of node i
  vector<int> D;
  void dfs(int v, int d) {
    D[v] = d;
    for (int i = 0; i < s; i++) {
      if (A[v][i]) dfs(A[v][i], d+1);
    }
  }

  // P[i][j] = the node that is 2^j levels above i
  vector<vector<int>> P;
  void initlca() {
    D.assign(n, -1); dfs(0, 0);
    P.assign(n, vector<int>(logn, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < s; j++)
        if (A[i][j]) P[A[i][j]][0] = i;
    for (int i = 0; i < n; i++)
      for (int j = 1; j < logn; j++)
        P[i][j] = P[P[i][j-1]][j-1];
  }

  int lca(int a, int b) {
    if (D[b] > D[a]) swap(a, b);
    for (int j = logn-1; D[a] > D[b]; j--)
      while (D[P[a][j]] >= D[b]) a = P[a][j];

    if (a == b) return a;
    for (int j = logn-1; j >= 0; j--)
      if (P[a][j] != P[b][j])
        a = P[a][j], b = P[b][j];

    return P[a][0];
  }
};

