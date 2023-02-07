#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n, m;

typedef long long ll;
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;
const ll mod = 1000000007;

mat zero() {
  return mat(n, vec(n, 0));
}

mat id() {
  mat i = zero();
  for (int j = 0; j < n; j++)
    i[j][j] = 1;
  return i;
}

mat matx(mat& a, mat& b) {
  mat r = zero();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        r[i][j] += a[i][k] * b[k][j];
        if (r[i][j] > mod) r[i][j] %= mod;
      }
    }
  }

  return r;
}

mat matexp(mat& a, ll e) {
  mat r = id();
  while (e > 0) {
    if (e % 2 == 1)
      r = matx(r, a);
    a = matx(a, a);
    e /= 2;
  }
  return r;
}

ll N;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> m;
  n = m+1;

  vec v(n, 0);
  v[m] = 1;

  mat a = zero();
  a[m][m] = 1;
  a[1][m] = 1;

  for (int i = 0; i < m; i++) {
    a[i+1][i] = 1;
  }

  a = matexp(a, N);

  vec ans(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i] += v[j]*a[j][i];
      if (ans[i] > mod) ans[i] %= mod;
    }
  }

  cout << ans.back() << endl;
}

