#include <bits/stdc++.h>
using namespace std;

int n, i, j, k, ans;
int A[600000];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (i = 0; i < (1 << (n+1)); i++)
    A[i] = -1;

  for (i = 0; i < (1 << n); i++) {
    k = 0;
    for (j = 0; j < n; j++)
      k = i & 1 << j ? (k << 1) + 1 : (k << 1);
    cin >> A[(1 << n) + k];
  }

  ans = (1 << (n+1)) - 1;
  while (n > 0) {
    for (i = (1 << n); i < 1 << (n+1); i += 2) {
      if (A[i] != -1 and A[i] == A[i+1]) {
        A[i / 2] = A[i];
        ans -= 2;
      }
    }
    n--;
  }

  cout << ans << '\n';
}