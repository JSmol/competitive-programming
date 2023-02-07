#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> pair<T, vi> hungarian(const vector<vector<T>>& A) {
  int n = (int) A.size(), m = (int) A[0].size(); T inf = numeric_limits<T>::max() / 2;
  vi way(m + 1), p(m + 1), used(m + 1), ans(n); vector<T> u(n + 1), v(m + 1), minv(m + 1);
  for (int i = 1; i <= n; i++) {
    int j0 = 0, j1 = 0; p[0] = i; minv.assign(m + 1, inf), used.assign(m + 1, 0);
    do {
      int i0 = p[j0]; j1 = 0; T delta = inf; used[j0] = true;
      for (int j = 1; j <= m; j++) if (!used[j]) {
        T cur = A[i0 - 1][j - 1] - u[i0] - v[j];
        if (cur < minv[j]) minv[j] = cur, way[j] = j0;
        if (minv[j] < delta) delta = minv[j], j1 = j;
      }
      for (int j = 0; j <= m; j++)
        if (used[j]) u[p[j]] += delta, v[j] -= delta;
        else minv[j] -= delta;
    } while (j0 =  j1, p[j0]);
    do { int j1 = way[j0]; p[j0] = p[j1]; j0 = j1; } while (j0);
  }
  for (int i = 1; i <= m; i++) if (p[i] > 0) ans[p[i] - 1] = i - 1;
  return {-v[0], ans};
}

vvi A;
vector<vector<ll>> B;
int n, m;

int main() {
  cin >> n >> m;
  A.assign(n, vector<int>(m));
  for (auto& r : A)
    for (auto& e : r)
      cin >> e;

  B.assign(n, vector<ll>(m));
  ll x = -1;
  for (int i = 1; i <= 200; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (A[j][k] <= i) {
          B[j][k] = i - A[j][k];
        } else {
          B[j][k] = numeric_limits<int>::max();
        }
      }
    }

    if (x == -1) x = hungarian(B).first;
    else x = min(hungarian(B).first, x);
  }

  cout << x << '\n';
}