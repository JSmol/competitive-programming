#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int dp[4004];

// the number of pieces with r remaining ribbon length
int f(int r) {
  if (r == 0) return 1;

  int& x = dp[r];
  if (x != -1) return x;

  x = 0;
  int v;
  if (r-a >= 0 and (v = f(r-a)))
    x = max(x, v+1);
  if (r-b >= 0 and (v = f(r-b)))
    x = max(x, v+1);
  if (r-c >= 0 and (v = f(r-c)))
    x = max(x, v+1);

  return x;
}

int main() {
  cin >> n >> a >> b >> c;
  for (int i = 0; i < n+1; i++) dp[i] = -1;

  cout << f(n)-1 << '\n';
}