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

/*  Usage: Build graph with add_edge(u, v), then call find_components()
 *  edge -> bridge (is this edge a bridge?)
 *  edge -> vcomp (biconnected component containing this edge)
 *  n_bcomps = # bridge connected components
 *  n_vcomps = # biconnected components
 *  cut_point[i] = is vertex i a cut vertex?
 *  bcomp[i] = which bridge connected component is vertex i in?
 *  bccs[bcomp[i]] = bridge connected component containing vertex i
 */

struct bicomp {
  struct edge {
    int u, v, vcomp; bool used, bridge;
    edge(int a, int b) : u(a), v(b) {}
    int other(int w) { return w == u ? v : u; }
  };
  int n, m, n_bcomps, n_vcomps, dfs_root, dfs_count, root_children;
  vector<int> dfs_num, dfs_low, cut_point, vcur, bcur, bcomp;
  vector<vector<int>> bccs, adj; vector<edge> edges;
  bicomp(int n) : n(n), m(0), adj(n) {}
  edge& get_edge(int i) { return edges[i]; }
  int add_edge(int u, int v) {
    adj[u].push_back(m), adj[v].push_back(m), edges.push_back({u, v});
    return m++;
  }
  void find_components() {
    dfs_num.assign(n, -1), dfs_low.assign(n, 0); dfs_count = 0;
    vcur.clear(); bcur.clear(); bccs.clear(); cut_point.assign(n, 0);
    bcomp.assign(n, -1); n_vcomps = 0; n_bcomps = 0;
    for (auto& e : edges) e.used = false, e.bridge = false;
    for (int v = 0; v < n; v++) if (dfs_num[v] == -1) {
      bcur = {v}; dfs_root = v; root_children = 0; dfs(v);
      cut_point[v] = (root_children > 1); make_bcomp(v);
    }
  }
  void make_vcomp(int i) {
    bccs.push_back({vcur.rbegin(), find(rall(vcur), i) + 1});
    vcur.resize(sz(vcur) - sz(bccs.back()));
    for (auto& j : bccs.back()) edges[j].vcomp = n_vcomps;
    n_vcomps++;
  }
  void make_bcomp(int v) {
    int u = -1; n_bcomps++;
    while (u != v) { u = bcur.back(); bcur.pop_back(); bcomp[u] = n_bcomps - 1; }
  }
  void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfs_count++;
    for (auto i : adj[u]) if (!edges[i].used) {
      auto& e = edges[i]; int v = e.other(u); e.used = true;
      if (dfs_num[v] == -1) {
        if (u == dfs_root) root_children++;
        vcur.push_back(i), bcur.push_back(v), dfs(v);
        if (dfs_low[v] > dfs_num[u]) { e.bridge = true; make_bcomp(v); }
        if (dfs_low[v] >= dfs_num[u]) { cut_point[u] = true; make_vcomp(i); }
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      } else {
        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        if (dfs_num[v] < dfs_num[u]) vcur.push_back(i);
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<vector<pair<int, long long>>> A(n), B(n);
  vector<tuple<int, int, long long>> E;
  for (int i = 0, a, b, c; i < m; i++) {
    cin >> a >> b >> c;
    A[a].push_back({b, c});
    B[b].push_back({a, c});
    E.push_back({a, b, c});
  }

  int s, t; cin >> s >> t;
  priority_queue<pair<long long, int>> Q;
  vector<long long> D1(n, -1);
  Q.push({0, s});
  while (!Q.empty()) {
    auto [d, v] = Q.top(); Q.pop();
    if (D1[v] != -1) continue;
    D1[v] = -d;
    for (auto& [a, w] : A[v]) {
      Q.push({d-w, a});
    }
  }

  vector<long long> D2(n, -1);
  Q.push({0, t});
  while (!Q.empty()) {
    auto [d, v] = Q.top(); Q.pop();
    if (D2[v] != -1) continue;
    D2[v] = -d;
    for (auto& [a, w] : B[v]) {
      Q.push({d-w, a});
    }
  }

  bicomp G(n);
  for (auto& [a, b, c] : E) {
    if (D1[a] + D2[b] + c == D1[t]) {
      G.add_edge(a, b);
    }
  }

  G.find_components();
  set<int> S = { s, t };
  for (int i = 0; i < n; i++) {
    if (G.cut_point[i])
      S.insert(i);
  }

  for (auto& s : S) cout << s << ' ';
  cout << endl;
}

