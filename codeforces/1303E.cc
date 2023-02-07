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

const int inf = 1 << 30;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int C; cin >> C;
  while (C--) {
    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<vector<int>> A(n+1, vector<int>(256, inf));
    for (int i = n-1; i >= 0; i--) {
      for (int j = 0; j < 256; j++) {
        if (int(s[i]) == j) A[i][j] = i;
        else A[i][j] = A[i+1][j];
      }
    }

    for (int k = 0; k <= m; k++) {
      // dp[i][j] = min len prefix of s for which t[0:i] and t[k:k+j] is made
      vector<vector<int>> dp(k+1, vector<int>(m-k+1, inf));
      dp[0][0] = 0;
      for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= m-k; j++) {
          if (i and dp[i-1][j] < inf) dp[i][j] = min(dp[i][j], A[dp[i-1][j]][int(t[i-1])] + 1);
          if (j and dp[i][j-1] < inf) dp[i][j] = min(dp[i][j], A[dp[i][j-1]][int(t[k+j-1])] + 1);
        }
      }

      if (dp[k][m-k] < inf) goto yes;
    }

    cout << "NO" << endl;
    continue;
    yes: cout << "YES" << endl;
  }
}

