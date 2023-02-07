#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k, r;
vector<ll> L;
vector<pair<ll, ll>> C;
ll dp[256][256];

ll f(ll s, ll l) {
  if (s == n and l == 1) return 0;
  if (s == n) return 1ll << 55;

  ll& x = dp[s][l];
  if (x != -1) return x;
  x = 1ll << 55;
  for (ll i = 1; i <= m; i++) {
    ll c = abs(i - l);
    if (c * k <= L[s]) {
      ll a = f(s + 1, i);
      x = min(x, a + L[s] + c * r + C[s].first + C[s].second * i);
    }
  }

  return x;
}

int main() {
  cin >> n >> m >> k >> r;

  L.resize(n);
  for (int i = 0; i < n; i++)
    cin >> L[i];

  C.resize(n, {0, 0});
  for (int i = 0; i < n-1; i++)
    cin >> C[i].first >> C[i].second;

  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
      dp[i][j] = -1;

  cout << f(0, 1) << endl;
}
