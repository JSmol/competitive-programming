#include <bits/stdc++.h>
using namespace std;

int n, e, d;
vector<int> D, E, A, R;

int main() {
  cin >> n >> e >> d;
  E.resize(e);
  for (auto& a : E) cin >> a;
  sort(begin(E), end(E));

  D.resize(d);
  for (auto& a : D) cin >> a;
  sort(begin(D), end(D));

  A.resize(n);
  R.resize(n);
  iota(begin(R), end(R), 0);
  int i = 0, j = 0, p = 0, c = 0;
  while (i < e) {
    if (j == d or E[i] < D[j]) {
      int k = (p + (E[i] - c)) % n;
      if (A[R[k]] == 0) {
        R.erase(begin(R) + k);
        n--;
        p = ((k+n) - 1) % n;
      } else {
        A[R[k]]--;
        p = k % n;
      }

      c = E[i];
      i++;
    } else {
      int k = (p + (D[j] - c)) % n;
      A[R[k]] = min(A[R[k]] + 1, 5);

      p = (p + (D[j] - c)) % n;
      c = D[j];
      j++;
    }

    if (n == 1) break;
  }
  if (n == 1) cout << R[0] << '\n';
  else cout << -1 << '\n';
}