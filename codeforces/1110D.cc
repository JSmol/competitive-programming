#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n, m;
vector<int> A;
int dp[1010101][3][3];

int f(int i, int p, int q) {
  if (i > m) return 0;

  int& x = dp[i][p][q];
  if (x != -1) return x;

  fo

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(m+11, 0);
  for (int i = 0, a; i < n; i++) cin >> a, A[a]++;

  for (int k = 0; k <= m; k++)
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
        dp[k][i][j] = -1;

  cout << f(0,0,0) << endl;

}

