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
double time() { return double(clock()) / CLOCKS_PER_SEC; }

const int inf = 1<<12;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int C = 1; C <= T; C++) {
    int n, m = 0; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, m += x;

    // dp[i][j] = best height at pos (i, j)
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[i][j] = min({
          (j - a[i-1] >= 0 ? max(dp[i-1][j-a[i-1]], j) : inf),
          (j + a[i-1] <= m ? max(dp[i-1][j+a[i-1]], j+a[i-1]) : inf)
        });
      }
    }

    string ans;
    if (dp[n][0] == inf) {
      ans = "IMPOSSIBLE";
    } else {
      for (int i = n, cur = 0; i >= 1; i--) {
        if (cur - a[i-1] >= 0 and dp[i][cur] >= dp[i-1][cur-a[i-1]]) {
          cur = cur - a[i-1];
          ans += 'U';
        } else {
          assert(cur + a[i-1] <= m and dp[i][cur] >= dp[i-1][cur+a[i-1]]);
          cur = cur + a[i-1];
          ans += 'D';
        }
      }
      reverse(all(ans));
    }

    cout << ans << endl;
  }
}

