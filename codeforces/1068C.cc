#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> A;

int main() {
  cin >> n >> m;
  A.resize(n+1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    A[min(a, b)].push_back(max(a, b));
  }

  vector<vector<int>> B(n+1);
  int o = 1;
  for (int i = 1; i <= n; i++) {
    if (A[i].size() == 0 and B[i].size() == 0) {
      cout << 1 << '\n';
      cout << i << ' ' << o << '\n';
      o++;
      continue;
    }

    cout << A[i].size() + B[i].size() << '\n';
    for (auto& b : B[i]) {
      cout << i << ' ' << b << '\n';
    }

    for (auto& a : A[i]) {
      cout << i << ' ' << o << '\n';
      B[a].push_back(o);
      o++;
    }
  }

}