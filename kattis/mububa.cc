#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

typedef long long ll;
int dp[3030][3030];
int B[3030][3030];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<ll> A(n), X(n);
  for (int i = 0; i < n; i++) cin >> A[i], X[i] = (i ? X[i-1] : 0) + A[i];

  auto f = [&] (int i, int j) { return X[j] - (i ? X[i-1] : 0); };

  // dp[i][j] = max(dp[j+1][k] + 1) : j+1 <= k < n
  for (int i = n-1; i >= 0; i--) {
    for (int j = n-1; j >= i; j--) {
      // for (int k = n-1; k >= j+1; k--) {
        // if (f(i, j) <= f(j+1, k)) dp[i][j] = max(dp[i][j], dp[j+1][k] + 1);
      // }

      auto lb = lower_bound(begin(X) + j + 1, end(X), f(0, j) + f(i, j));
      if (lb != end(X)) {
        int k = distance(begin(X), lb);
        dp[i][j] = B[j+1][k] + 1;
      }

      B[i][j] = max(dp[i][j], B[i][j+1]);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[0][i] + 1);

  cout << ans << endl;
}

