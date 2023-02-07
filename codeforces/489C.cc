#include <bits/stdc++.h>
using namespace std;

int m, s;
int A[101];
int B[101];

int dp[101][909];

bool f(int n, int t) {
  if (n == 0 and t == 0) return true;

  int& x = dp[n][t];
  if (x != -1) return x;

  for (int i = 0; i <= 9; i++) {
    if (n == m and i == 0) continue;
    if (t-i >= 0 and n-1 >= 0 and f(n-1, t-i)) {
      A[n] = i;
      return true;
    }
  }
  return x = 0;
}

bool g(int n, int t) {
  if (n == 0 and t == 0) return true;

  int& x = dp[n][t];
  if (x != -1) return x;

  for (int i = 9; i >= 0; i--) {
    if (n == m and i == 0) continue;
    if (t-i >= 0 and n-1 >= 0 and g(n-1, t-i)) {
      B[n] = i;
      return true;
    }
  }
  return x = 0;
}

int main() {
  cin >> m >> s;

  if (m == 1 and s == 0) {
    cout << 0 << ' ' << 0 << '\n';
    return 0;
  }

  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= s; j++)
      dp[i][j] = -1;

  bool ans = f(m, s);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= s; j++)
      dp[i][j] = -1;
  g(m, s);

  if (ans) {
    for (int i = m; i > 0; i--)
      cout << A[i];
    cout << ' ';

    for (int i = m; i > 0; i--)
      cout << B[i];
    cout << '\n';
  } else {
    cout << "-1 -1\n";
  }
}