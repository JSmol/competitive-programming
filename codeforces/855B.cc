#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

typedef long long ll;

ll n;
ll pqr[3];
vector<ll> A;
ll dp[100001][3];
bool v[100001][3];

ll f(int i, int m) {
  if (m == 3) return 0;
  if (i == n) return -(1ll << 62);

  ll& x = dp[i][m];
  if (v[i][m]) return x;
  v[i][m] = true;

  x = max(f(i, m+1) + pqr[m] * A[i], f(i+1, m));
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> pqr[0] >> pqr[1] >> pqr[2];
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      dp[i][j] = -1;

  cout << f(0, 0) << endl;
}

