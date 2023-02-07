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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, n; cin >> m >> n;
  map<string, int> N;
  map<int, string> Nrev;
  map<string, vector<int>> M;
  for (int i = 0; i < m; i++) {
    string s; cin >> s;
    N[s] = sz(N);
    Nrev[N[s]] = s;
    int k; cin >> k;
    M[s] = vector<int>(k, 0);
    for (auto& x : M[s]) cin >> x;
  }

  // debug(N);
  // debug(M);

  for (int ans = 1; ans <= n; ans++) {
    Flow<int> G(m+n+2);
    int S = m+n;
    int T = m+n+1;

    for (auto& [x, d] : M) {
      G.add_edge(S, N[x], ans);
      for (auto& y : d) {
        G.add_edge(N[x], m+y-1, 1);
      }
    }

    for (int i = 0; i < n; i++) 
      G.add_edge(m+i, T, 2);

    if (G.max_flow(S, T) == 2*n) {
      cout << ans << endl;

      vector<vector<string>> A(n);
      auto edges = G.edges;
      auto adj = G.A;

      for (int i = 0; i < m; i++) {
        for (auto idx : adj[i]) {
          if (edges[idx].flow > 0) {
            assert(edges[idx].to - m < n);
            A[edges[idx].to - m].push_back(Nrev[i]);
          }
        }
      }

      for (int i = 0; i < n; i++)
        cout << "Day " << i+1 << ": " << A[i][0] << ' ' << A[i][1] << endl;
  
      return 0;
    }
  }
}

