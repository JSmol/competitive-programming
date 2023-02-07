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

int n, k;
int A[505];
int dp[2][505][505];
vector<int> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> A[i];

  dp[1][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int x = 0; x <= k; x++) {
      for (int y = 0; y <= k; y++) {
        dp[i%2][x][y] |= dp[(i+1)%2][x][y];
        if (y-A[i] >= 0)
          dp[i%2][x][y] |= dp[(i+1)%2][x][y-A[i]];
        if (y-A[i] >= 0 and x-A[i] >= 0)
          dp[i%2][x][y] |= dp[(i+1)%2][x-A[i]][y-A[i]];
      }
    }
  }

  for (int i = 0; i <= k; i++)
    if (dp[(n+1)%2][i][k]) ans.push_back(i);

  cout << ans.size() << endl;
  cout << ans << endl;
}

