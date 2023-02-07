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

/*
  ev = sum (p(outcome) * v(outcome))
*/

// dp[i][a][s] = expected value having considered i papers,
//               a of which have been accepted, and 
//               s have been submitted

typedef long double ld;
vector<int> A;
int n;

ld p(int i) {
  return (ld) A[i] / 100.0L;
}

ld v(int a, int s) {
  if (a == 0) return 0;
  return pow((ld) a, (ld) a / (ld) s);
}

ld f(int x) {
  ld dp[101][101];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = 0;

  dp[0][0] = 1.0L - p(0);
  dp[0][1] = p(0);
  for (int i = 1; i < x; i++) {
    for (int a = 0; a <= x; a++) {
      dp[i][a] = (a ? dp[i-1][a-1] * p(i) : 0) + dp[i-1][a] * (1.0L - p(i));
    }
  } 

  ld ans = 0.0L;
  for (int a = 0; a <= x; a++)
    ans += dp[x-1][a] * v(a, x);

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  sort(all(A));
  reverse(all(A));

  debug(f(3));

  ld ans = 0.0L;
  for (int i = 0; i <= n; i++)
    ans = max(ans, f(i));

  cout << setprecision(9) << fixed << ans << endl;
}

