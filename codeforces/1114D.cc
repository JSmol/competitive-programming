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

int n;
vector<int> A;
int dp[5050][5050][2];

int f(int l, int r, int s) {
  if (r-l <= 1) return A[l] != A[r];

  int& x = dp[l][r][s];
  if (x != -1) return x;

  if (s)
    x = min(f(l, r-1, 0) + (A[r] != A[l]), f(l, r-1, 1) + (A[r] != A[r-1]));
  else
    x = min(f(l+1, r, 0) + (A[l] != A[l+1]), f(l+1, r, 1) + (A[l] != A[r]));

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (int i = 0; i < n; i++) cin >> A[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < 2; k++)
        dp[i][j][k] = -1;

  cout << min(f(0,n-1,0), f(0,n-1,1)) << endl;
}

