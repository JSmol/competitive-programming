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

int dp[303][55];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, w; cin >> n >> w;
  vector<vector<int>> A(w+1), X(w+1);
  for (int i = 0, k; i <= w; i++) {
    cin >> k;
    A[i].assign(k, 0);
    for (int j = 0; j < k; j++) {
      cin >> A[i][j];
    }

    X[i].assign(k, 0);
    for (int j = 0; j < k; j++) {
      cin >> X[i][j];
    }
  }

  int best = 1 << 30;;
  for (int i = 0; i <= n; i++) {
    // dp[n][w] = max(dp[n-s[i]][w+1] + p[i])
    for (int j = w; j >= 0; j--) {
      if (j == 0) {
        for (int k = 0; k < sz(A[j]); k++) {
          if (dp[i][j] < ((j < w ? dp[max(0, i - X[j][k])][j+1] : 0) + min(i, X[j][k])*A[j][k])) {
            dp[i][j] = ((j < w ? dp[max(0, i - X[j][k])][j+1] : 0) + min(i, X[j][k])*A[j][k]);
            best = A[j][k];
          } else 
          if (dp[i][j] == ((j < w ? dp[max(0, i - X[j][k])][j+1] : 0) + min(i, X[j][k])*A[j][k])) {
            best = min(best, A[j][k]);
          }
        }
      } else {
        for (int k = 0; k < sz(A[j]); k++) {
          dp[i][j] = max(dp[i][j], (j < w ? dp[max(0, i - X[j][k])][j+1] : 0) + min(i, X[j][k])*A[j][k]);
        }
      }
    }
  }
  
  cout << dp[n][0] << endl;
  cout << best << endl;
}

