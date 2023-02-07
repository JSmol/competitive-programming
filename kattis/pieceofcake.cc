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

typedef long long ll;
int n, k;
vector<pair<long double, long double>> A;

long double area(pair<long double, long double>& a, pair<long double, long double>& b, pair<long double, long double>& c) {
  return abs(((b.fst - a.fst)*(c.snd - a.snd) - (c.fst - a.fst)*(b.snd - a.snd)) / 2);
}

long double dp[2555][2555];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;

  for (int i = 0; i < n; i++) dp[i][0] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(i, k); j++)
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

  A.assign(n, {});
  for (auto& a : A) cin >> a.fst >> a.snd;

  long double t = 0;
  for (int i = 0; i < n-2; i++) t += area(A[0], A[i+1], A[i+2]);

  vector<long double> r;
  long double ans = t;
  for (int i = 0; i < n; i++) {
    long double a = 0;
    for (int j = 0; j < n-k; j++) {
      a += area(A[i], A[(i+j+1)%n], A[(i+j+2)%n]);
      r.push_back(a*dp[n-j-3][k-2]/dp[n][k]);
    }
  }

  sort(ALL(r));
  reverse(ALL(r));
  for (auto& v : r)
    ans-=v;

  cout << setprecision(9) << ans << endl;
}

