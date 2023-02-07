#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> A;
vector<int> D;
vector<bool> V;

int f(int v) {
  V[v] = true;
  if (A[v].size() == 1) return D[v] = 0;

  int d = 1 << 30;
  for (auto& u : A[v])
    if (!V[u])
      d = min(d, f(u) + 1);

  return D[v] = d;
}

int main() {
  cin >> n >> k;
  A.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    A[a].push_back(b);
    A[b].push_back(a);
  }

  D.assign(n+1, -1);
  for (int i = 1; i <= n; i++) {
    if (D[i] == -1) {
      V.assign(n+1, false);
      D[i] = f(i);
    }
  }

  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (D[m] < D[i]) {
      m = i;
    }
  }
  
  if (D[m] != k) {
    cout << "No" << '\n';
    return 0;
  }
  
  queue<int> Q;
  Q.push(m);

  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();


    if (A[v].size() != 1) {
      if (A[v].size() < 4 and v != m) {
        cout << "No" << '\n';
        return 0;
      }
      if (A[v].size() < 3 and v == m) {
        cout << "No" << '\n';
        return 0;
      }
    }

    bool p = false;
    for (auto a : A[v]) {
      if (D[a] == D[v]-1) {
        Q.push(a);
        continue;
      }
      if (D[a] == D[v]+1 and !p) {
        p = true;
        continue;
      }
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
}