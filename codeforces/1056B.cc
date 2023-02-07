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
ll n, m;
ll A[1001][1001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    A[0][i] = (i*i) % m;

  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      A[i][j] = A[0][i] + A[0][j];
      if (A[i][j] % m == 0)
        ans++;
    }
  }

  ll f = n / m;
  ans *= f * f;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (i <= n % m and A[i][j] % m == 0)
        ans += f;
      if (j <= n % m and A[i][j] % m == 0)
        ans += f;
      if ((i <= n % m and j <= n % m) and A[i][j] % m == 0)
        ans++;
    }
  }

  cout << ans << endl;
}

