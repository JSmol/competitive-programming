#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

/*  Sort of like MST but with some funny conditions on the leaves (and a few GOTCHA's).
 */

struct UF {
  int n; vector<int> A;
  UF (int n) : n(n), A(n) { iota(all(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, p; cin >> n >> m >> p;
  vector<int> P(n);
  for (int i = 0, x; i < p; i++) cin >> x, P[x-1] = 1;

  vector<vector<pair<int, int>>> A(n);
  vector<tuple<int, int, int>> E;

  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w; u--; v--;
    A[u].push_back({v, w});
    A[v].push_back({u, w});
    E.emplace_back(w, u, v);
  }

  // special cases
  if (n <= 2) {
    if (n == 2 and sz(A[0])) cout << A[0][0].snd << endl;
    else if (n == 2) cout << "impossible" << endl;
    else if (n == 1) cout << 0 << endl;
    else assert(0);
    return 0;
  }
  
  set<int> S;
  for (int i = 0; i < n; i++)
    if (!P[i]) S.insert(i);

  UF uf(n);
  sort(all(E));

  int x = 1;
  int ans = 0;
  for (auto [w, u, v] : E) {
    if (uf.connected(u, v) or P[u] or P[v]) continue;
    uf.merge(u, v);
    ans += w;
    x++;
  }

  vector<int> V(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
  if (sz(S) != x) { goto done; } // funny goto...

  for (int i = 0; i < n; i++) {
    if (!P[i]) {
      for (auto& a : A[i]) {
        Q.push({a.snd, a.fst});
      }
    }
  }

  while (!Q.empty()) {
    auto [w, v] = Q.top(); Q.pop();
    if (!S.count(v)) {
      S.insert(v);
      ans += w;
    }
  }
  
  if (n == 1 or sz(S) == n) cout << ans << endl;
  else {
done:
    cout << "impossible" << endl;
  }
}

