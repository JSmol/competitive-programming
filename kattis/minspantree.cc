#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

int n, m;
vector<vector<pair<int, int>>> A, T;

struct UF {
  int n; vector<int> A;
  UF (int size) {
    n = size; A = vector<int>(n);
    iota(begin(A), end(A), 0);
  }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

const int inf = (1<<30);
int mst() {
  set<pair<int, pair<int, int>>> S;
  for (int i = 0; i < n; i++)
    for (auto& a : A[i])
      S.insert({a.snd, {i, a.fst}});

  UF uf(n);
  T.assign(n, {});
  int c = 0; int e = 0;
  for (auto& s : S) {
    int u = s.snd.fst; int v = s.snd.snd;
    if (uf.connected(u, v)) continue;

    e++;
    c += s.fst;
    uf.merge(u, v);
    T[u].push_back({v, s.fst});
    T[v].push_back({u, s.fst});
    if (e == n-1) break;
  }

  return (e == n-1 ? c : inf);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (cin >> n >> m and n != 0) {
    A.assign(n, {});
    for (int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w;
      A[u].push_back({v, w});
      A[v].push_back({u, w});
    }

    int c = mst();
    if (c != inf) {
      cout << c << endl;
      set<pair<int, int>> ans;
      for (int v = 0; v < n; v++) for (auto& a : T[v]) ans.insert({min(v, a.fst), max(v, a.fst)});
      for (auto& a : ans) cout << a.fst << ' ' << a.snd << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
}

