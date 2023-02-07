#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, T, s, t, k;
vector<vector<pair<ll, ll>>> G;
vector<ll> S;


bool f(ll d) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
  vector<ll> D(n, -1);
  if (S[s] >= d)
    PQ.push({0, s});

  while (!PQ.empty()) {
    ll v = PQ.top().second, w = PQ.top().first;
    PQ.pop();

    if (D[v] != -1) continue;
    D[v] = w;

    for (auto a : G[v])
      if (S[a.first] >= d)
        PQ.push({w + a.second, a.first});
  }
  return D[t] != -1 and D[t] <= T;
}

int main() {
  cin >> n >> m >> T;

  G.resize(n);
  for (ll i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  cin >> s >> t >> k;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
  S.resize(n, -1);
  for (ll i = 0; i < k; i++) {
    ll v;
    cin >> v;
    PQ.push({0, v});
  }

  while (!PQ.empty()) {
    ll v = PQ.top().second, w = PQ.top().first;
    PQ.pop();

    if (S[v] != -1) continue;
    S[v] = w;

    for (auto& a : G[v]) 
      PQ.push({w + a.second, a.first});
  }

  ll l = 0, h = 1ll << 60;
  while (h - l > 3) {
    ll m = (h + l) / 2;
    (f(m) ? l : h) = m;
  }

  while (f(l)) l++;

  cout << max(l - 1, 0ll) << '\n';
}