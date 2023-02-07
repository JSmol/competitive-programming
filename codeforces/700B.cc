#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> G;
vector<bool> V;
vector<int> U;
vector<int> D;

int main() {
  cin >> n >> k;

  U.assign(n+1, 0);
  for (int i = 0; i < 2*k; i++) {
    int a;
    cin >> a;
    U[a]++;
  }

  G.resize(n+1);
  D.assign(n+1, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    D[u]++; D[v]++;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  queue<int> Q;
  for (int i = 1; i <= n; i++) 
    if (D[i] == 1)
      Q.push(i);

  long long ans = 0;
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();

    D[v] = 0;
    if (U[v] > k) {
      int d = U[v] - k;
      k -= d;
      U[v] -= 2 * d;
    }

    for (const auto& a : G[v]) {
      if (D[a] > 0) {
        D[a]--;
        if (D[a] == 1)
          Q.push(a);

        U[a] += U[v];
        ans += U[v];
        U[v] = 0;
      }
    }
  }

  cout << ans << '\n';
}