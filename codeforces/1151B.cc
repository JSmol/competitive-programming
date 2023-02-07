#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int n, m;
vector<vector<int>> A;
vector<int> ans;
int dp[505][1111];

int f(int r, int s) {
  if (r == n) return s != 0;

  int& x = dp[r][s];
  if (x != -1) return x;
  for (int i = 0; i < m; i++) {
    x = f(r+1, s^A[r][i]);
    if (x) {
      ans.push_back(i+1);
      return true;
    }
  }

  return x = false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, vector<int>(m));
  for (auto& r : A) for (auto& e : r) cin >> e;

  for (int i = 0; i < 505; i++) 
    for (int j = 0; j < 1111; j++) 
      dp[i][j] = -1;

  if (f(0,0)) {
    reverse(all(ans));
    cout << "TAK" << endl << ans << endl;
  } else {
    cout << "NIE" << endl;
  }
}

