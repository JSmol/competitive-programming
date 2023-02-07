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

