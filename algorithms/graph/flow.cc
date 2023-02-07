/*  O(n^2 m) maximum flow.
 *  flow data is stored in edge.flow
 */

template<typename T> struct Flow {
  struct edge { int to; T flow, cap; }; T inf = numeric_limits<T>::max();
  int n, m; vector<int> dist, work; queue<int> q; vector<edge> edges; vector<vector<int>> A;
  Flow(int n) : n(n), m(0), A(n) {}
  int add_edge(int a, int b, T cap) {
    A[a].push_back(m++), A[b].push_back(m++);
    edges.push_back({b, 0, cap}), edges.push_back({a, 0, 0});
    return m-2; // change {a, 0, 0} to {b, 0, cap} above for bi-directional edges.
  }
  bool bfs(int s, int t) {
    dist.assign(n, -1); dist[s] = 0; q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto& i : A[u]) {
        edge& e = edges[i]; int v = e.to;
        if (dist[v] < 0 and e.flow < e.cap) dist[v] = dist[u] + 1, q.push(v);
      }
    }
    return dist[t] >= 0;
  }
  T dfs(int u, int t, T f) {
    if (u == t) return f;
    for (int& i = work[u]; i < sz(A[u]); i++) {
      auto& e = edges[A[u][i]]; auto& rev = edges[A[u][i] ^ 1];
      if (e.flow < e.cap and dist[e.to] == dist[u] + 1) {
        T df = dfs(e.to, t, min(f, e.cap - e.flow));
        if (df > 0) { e.flow += df; rev.flow -= df; return df; }
      }
    }
    return 0;
  }
  T max_flow(int s, int t) {
    T res = 0; for (auto& e : edges) e.flow = 0;
    while (work.assign(n, 0), bfs(s, t))
      while (T delta = dfs(s, t, inf)) res += delta;
    return res;
  }
};

