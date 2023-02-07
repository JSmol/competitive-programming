#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> V;
int n;

pair<int, int> dfs(int d, int v) {
  if (V[v]) return {0, 0};

  V[v] = true;
  pair<int, int> r = {d, v};
  for (const auto& a : G[v])
    r = max(r, dfs(d+1, a));
  
  return r;
}

int main() {
  cin >> n;
  G.assign(n, {});
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  V.assign(n, false);
  auto s = dfs(0, 0);

  V.assign(n, false);
  auto t = dfs(0, s.second);

  cout << "tree diam = " << t.first << endl;
  cout << "path = " << s.second << ' ' << t.second << endl;
}

