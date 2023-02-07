#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

int n, k;
vector<int> A;
int dp[5050][5050];

int f(int i, int t) {
  if (i == n or t == k) return 0;

  int& x = dp[i][t];
  if (x != -1) return x;

  int j = upper_bound(ALL(A), A[i]+5) - begin(A);
  x = max(f(i+1, t), f(j, t+1) + j-i);

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  sort(ALL(A));

  for (int i = 0; i <= n; i++) fill(dp[i], dp[i]+k+1, -1);
  cout << f(0, 0) << endl;
}

