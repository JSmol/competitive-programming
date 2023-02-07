#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<int>> G;
vector<int> H;

vector<vector<int>> A;
vector<bool> S;
vector<bool> V;
vector<int> D;
queue<int> Q;

bool dfs(int v) {
  // cout << "dfs at " << v << '\n';
  if (!S[v])
    return S[v] = true;

  bool r = false;
  for (auto& a : G[v])
    r |= dfs(a);

  return r;
}

int main() {
  cin >> n >> k >> m;
  G.resize(n+1);
  H.resize(n+1, 0);
  D.resize(n+1, 0);
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);

    assert(H[v] == 0);
    H[v] = u;
    D[u]++;
  }

  A.resize(n+1);
  S.assign(n+1, true);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    A[s].push_back(t);
    S[t] = false;
  }

  for (int i = 1; i <= n; i++)
    if (G[i].empty())
      Q.push(i);

  int ans = 0;
  V.assign(n+1, false);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();

    if (V[v]) continue;
    V[v] = true;
    // cout << "exploring node " << v << '\n';

    D[H[v]]--;
    if (D[H[v]] == 0) 
      Q.push(H[v]);

    // if (!A[v].empty())
    //   ans += dfs(v);
    for (auto& s : A[v])
      if (!S[s])
        ans += dfs(v);

  }

  for (int i = 1; i <= n; i++)
    assert(S[i]);

  cout << ans << '\n';
}