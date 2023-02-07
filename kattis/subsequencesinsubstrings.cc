#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
ll dp[101010][101][3];
string s, t;
ll n, m;

ll f(int i, int j, int k) {
  ll& x = dp[i][j][k];
  if (x != -1) return x;

  if (i == n) return x = (j == m);
  if (j == m and k == 2) return x = f(i+1, j, k);
  if (j == m and k == 1) return x = f(i+1, j, 1) + f(i+1, j, 2);

  x = 0;
  if (k == 1) {
    x += f(i+1, j + (s[i] == t[j]), 1);
  } else {
    x += f(i+1, j, 0) + f(i+1, j + (s[i] == t[j]), 1);
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s >> t;
  n = s.length();
  m = t.length();

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;

  cout << f(0, 0, 0) << endl;
}

