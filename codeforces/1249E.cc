#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, c;
  cin >> n >> c;

  vector<ll> A(n-1);
  for (auto& a : A) cin >> a;

  vector<ll> B(n-1);
  for (auto& b : B) cin >> b;

  ll dp[202020][2];
  dp[0][1] = c;
  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i-1][0] + A[i-1], dp[i-1][1] + B[i-1]);
    dp[i][1] = min(dp[i][0] + c, dp[i-1][1] + B[i-1]);
  }

  for (int i = 0; i < n; i++) cout << dp[i][0] << ' ';
  cout << endl;
}

