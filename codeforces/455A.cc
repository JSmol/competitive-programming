#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll A[100001];
ll dp[100001];

// the most points i can have by considering every value greater or equal to i
ll f(int i) {
  cout << i << ' ';
  if (i >= 100001) return 0;

  ll& x = dp[i];
  if (x != -1) return x;
  x = max(f(i+1), f(i+2)+A[i]*i);
  return x;
}

int main() {
  cin >> n;

  // count occurences of numbers
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    A[v]++;
  }

  dp[0] = 0;
  dp[1] = A[1];

  // either i take the value before me, or myself and 2 before me.
  for (ll i = 2; i < 100001; i++)
    dp[i] = max(dp[i-1], dp[i-2]+A[i]*i);

  cout << dp[100000] << '\n';
}