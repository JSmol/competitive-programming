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

typedef long long ll;
ll n, m;
ll A[300003];
ll dp[300003][3][3];

ll f(int i, int s, int t) {
  ll& x = dp[i][s][t];
  if (x != -1) return x;
  if (s == 2) return x = 0;
  if (i == n) return x = 0;
  if (s == 1 and t == 2) x = max({f(i+1, s, t) + A[i], f(i+1, 2, 2)});
  if (s == 1 and t == 1) x = max({f(i+1, s, t) + A[i] * m, f(i+1, s, 2) + A[i], f(i+1, 2, 2)});
  if (s == 1 and t == 0) x = max({f(i+1, s, t) + A[i], f(i+1, s, 1) + A[i] * m, f(i+1, 2, 2)});
  if (s == 0 and t == 0) x = max({f(i+1, 1, 0) + A[i], f(i+1, 1, 1) + A[i] * m, f(i+1, s, t)});
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i <= n; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) dp[i][j][k] = -1;
  cout << f(0, 0, 0) << endl;
}

