#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;
set<int> S;

int main() {
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  string ans;
  int p = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;

    if (S.count(b)) {
      ans += "0 ";

    } else {
      for (; k < n; k++) {
        if (A[k] == b) {
          ans += to_string((k - p) + 1) + ' ';
          k++;
          p = k;
          break;
        }
        S.insert(A[k]);
      }
    }
  }
  cout << ans << '\n';
}