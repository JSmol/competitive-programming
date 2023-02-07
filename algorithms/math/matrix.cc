/*  basic square matrix operations
 */

typedef long long ll;
const ll mod = 1e9+9;
struct matrix {
  int n; vector<vector<ll>> A;
  matrix(int n, ll v) : n(n), A(n, vector<ll>(n, v)) {}
  matrix(int n) : n(n), A(n, vector<ll>(n, 0)) { for (int i = 0; i < n; i++) A[i][i] = 1; }
  vector<ll>& operator[](int i) { return A[i]; }
  matrix operator*(matrix& left) {
    auto& a = *this;
    auto& b = left;
    matrix r(n, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          r[i][j] += (a[i][k] * b[k][j]) % mod,
          r[i][j] %= mod;
    return r;
  }
  matrix operator^(ll e) {
    auto b = *this;
    matrix r(n);
    while (e > 0) {
      if (e & 1) r = r * b, e--;
      else b = b * b, e /= 2;
    }
    return r;
  }
};

