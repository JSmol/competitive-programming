#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;
int dp[101010];

// longest subsegment starting on pos i
int f(int i) {
  if (i == n-1) return dp[i] = 1;

  int& x = dp[i];
  if (x != -1) return x;

  x = 1;
  if (A[i] <= A[i+1]) x = f(i+1) + 1;
  else f(i+1);

  return x;
}

int main() {
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  fill(dp, dp+n+1, -1);
  f(0);
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(dp[i], ans);

  cout << ans << '\n';

}