#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

typedef long long ll;
const ll inf = 1ll << 60;

struct Centroid {
  int n, cnt = 0, croot; vector<vector<int>> adj, cadj; vector<int> par, mark, size;
  Centroid(int n) : n(n), adj(n), cadj(n), par(n, -1), mark(n), size(n) {}
  void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }
  int dfs(int u, int p) {
    size[u] = 1;
    for (int v : adj[u]) if (v != p and !mark[v]) dfs(v, u), size[u] += size[v];
    return size[u];
  }
  int find_centroid(int u, int p, int s) {
    for (int v : adj[u]) if (v != p and !mark[v]) 
      if (size[v] * 2 > s) return find_centroid(v, u, s);
    return u;
  }
  int find_centroid(int src) { return find_centroid(src, -1, dfs(src, -1)); }
  int decompose(int src = 0) {
    int c = find_centroid(src); mark[c] = 1;
    for (int u : adj[c]) if (!mark[u]) {
      int v = decompose(u);
      cadj[c].push_back(v), par[v] = c;
    }
    return croot = c;
  }
};

template<typename T> struct DynamicHull {
  struct Line {
    typedef typename multiset<Line>::iterator It;
    T a, b; mutable It me, endit, none;
    Line(T a, T b, It endit) : a(a), b(b), endit(endit) {}
    bool operator<(const Line& rhs) const {
      if (rhs.endit != none) return a < rhs.a;
      if (next(me) == endit) return 0;
      return (b - next(me)->b) < (next(me)->a - a) * rhs.a;
    }
  };
  multiset<Line> lines;
  void add(T a, T b) {
    auto bad = [&](auto y) {
      auto z = next(y);
      if (y == lines.begin()) {
        if (z == lines.end()) return false;
        return y->a == z->a and z->b >= y->b;
      }
      auto x = prev(y);
      if (z == lines.end()) return y->a == x->a and x->b >= y->b;
      return (x->b-y->b) * (z->a-y->a) >= (y->b-z->b) * (y->a-x->a);
    };
    auto it = lines.emplace(a, b, lines.end()); it->me = it;
    if (bad(it)) { lines.erase(it); return; }
    while (next(it) != lines.end() and bad(next(it))) lines.erase(next(it));
    while (it != lines.begin() and bad(prev(it))) lines.erase(prev(it));
  }
  T query(T x) {
    auto it = lines.lower_bound(Line{x, 0, {}});
    return it->a * x + it->b;
  }
};

int n;
vector<ll> C, D, ans;
vector<vector<int>> CA;
vector<DynamicHull<ll>> H;
vector<vector<pair<int, ll>>> A;

void dfs3(int v, ll dist, int p, int d, int c) {
  ans[v] = min(ans[v], -H[c].query(C[v]) + dist);
  for (auto& a : A[v]) {
    if (a.fst != p and D[a.fst] >= d) {
      dfs3(a.fst, a.snd + dist, v, d, c);
    }
  }
}

void dfs2(int v, ll dist, int p, int d, int c) {
  H[c].add(-C[v], -dist);
  for (auto& a : A[v]) {
    if (a.fst != p and D[a.fst] >= d) {
      dfs2(a.fst, a.snd + dist, v, d, c);
    }
  }
}

void dfs1(int v, int d) {
  D[v] = d;
  for (auto a : CA[v]) {
    dfs1(a, d+1);
  }

  dfs2(v, 0, -1, d, v);
  dfs3(v, 0, -1, d, v);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  C.assign(n, 0);
  for (auto& a : C) cin >> a;
  Centroid T(n);
  A.assign(n, {});
  for (int i = 0, u, v, w; i < n-1; i++) {
    cin >> u >> v >> w; u--; v--;
    A[u].push_back({v, w});
    A[v].push_back({u, w});
    T.add_edge(u, v);
  }

  ans.assign(n, inf);
  H.assign(n, {});
  D.assign(n, -1);

  int root = T.decompose();
  CA = T.cadj;

  dfs1(root, 0);
  cout << accumulate(all(ans), 0ll) << endl;
}
