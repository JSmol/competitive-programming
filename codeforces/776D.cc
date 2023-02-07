#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

struct SCC {

  int n, c;
  vector<vector<int>> G, H;
  vector<int> ord, comp;
  vector<bool> V;

  SCC(int n) : n(n), G(n), H(n) { };

  void add_edge(int u, int v) {
    G[u].push_back(v);
    H[v].push_back(u);
  }

  void dfs1(int v) { 
    V[v] = true;
    for (auto& u : G[v])
      if (!V[u]) dfs1(u);
    ord.push_back(v);
  }

  void dfs2(int v) {
    comp[v] = c;
    for (auto& u : H[v])
      if (comp[u] == -1) dfs2(u);
  }

  vector<int> scc() {
    V.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (!V[i]) dfs1(i);

    comp.assign(n, -1); c = 0;
    for (int i = 0; i < n; i++) {
      int v = ord[n-1-i];
      if (comp[v] == -1) dfs2(v), c++;
    }

    return comp;
  }

  vector<vector<int>> dag() {
    set<pair<int, int>> S;
    vector<vector<int>> dag(c);
    for (int a = 0; a < n; a++) {
      for (auto& b : G[a]) {
        if (comp[a] == comp[b]) continue;
        if (S.count({comp[a], comp[b]})) {
          dag[a].push_back(b);
          S.insert({a, b});
        }
      }
    }
    return dag;
  }
};

int VAR(int i) { return 2*i; }
int NOT(int i) { return i^1; }

struct SAT {

  int n; SCC scc;

  SAT(int n) : n(n), scc(2*n) {}

  void add_or(int a, int b) {
    if (a == NOT(b)) return;
    scc.add_edge(NOT(a), b);
    scc.add_edge(NOT(b), a);
  }
  
  void add_true(int a) { add_or(a, a); }
  void add_false(int a) { add_or(NOT(a), NOT(a)); }
  void add_xor(int a, int b) { add_or(a, b); add_or(NOT(a), NOT(b)); }

  pair<bool, vector<bool>> solve() {
    auto comp = scc.scc(); vector<bool> ans(n);
    for (int i = 0; i < 2*n; i += 2) {
      if (comp[i] == comp[i+1]) return {false, {}};
      ans[i/2] = (comp[i] > comp[i+1]);
    }
    return {true, ans};
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  trav (a, A) cin >> a;

  vector<vector<int>> X(n);
  rep (i, 0, m) {
    int x; cin >> x;
    rep (j, 0, x) {
      int y; cin >> y; y--;
      X[y].push_back(i);
    }
  }

  SAT sat(m);
  rep (i, 0, n) {
    if (A[i]) {
      sat.add_xor(VAR(X[i][0]), NOT(VAR(X[i][1])));
    } else {
      sat.add_xor(VAR(X[i][0]), VAR(X[i][1]));
    }
  }

  auto [x, y] = sat.solve();
  if (x) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

