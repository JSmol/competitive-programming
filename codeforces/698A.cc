#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n;
vector<int> A;
int dp[101][3];

int f(int i, int j) {
  if (i == n) return 0;

  int& x = dp[i][j];
  if (x != -1) return x;

  int& a = A[i];
  x = f(i+1, 0);

  switch (a) {
    case 1:
      if (j != 1)
        x = max(x, f(i+1, 1) + 1);
      break;

    case 2:
      if (j != 2)
        x = max(x, f(i+1, 2) + 1);
      break;

    case 3:
      if (j != 1)
        x = max(x, f(i+1, 1) + 1);
      if (j != 2)
        x = max(x, f(i+1, 2) + 1);
      break;
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      dp[i][j] = -1;

  cout << n - f(0, 0) << endl;
}
