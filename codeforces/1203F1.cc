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

int dp[111][111111];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r; cin >> n >> r;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  vector<int> I(n);
  iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return a[i] < a[j]; });

  int ans = 0;
  vector<pair<int, int>> A;
  for (int i = 0; i < n; i++) {
    if (b[I[i]] >= 0 and a[I[i]] <= r) {
      r += b[I[i]]; ans++;
    } else {
      if (b[I[i]] < 0) A.push_back({ a[I[i]], b[I[i]] });
    }
  }

  sort(all(A), [] (auto x, auto y) { return x.fst + x.snd < y.fst + y.snd; });
  for (int i = 0; i < sz(A); i++) {
    for (int j = 0; j <= r; j++) {
      if (j >= A[i].fst and j + A[i].snd >= 0) dp[i][j] = max((i ? dp[i-1][j + A[i].snd] : 0) + 1, (i ? dp[i-1][j] : 0));
      else dp[i][j] = (i ? dp[i-1][j] : 0);
    }
  }

  if (sz(A) > 0) ans += dp[sz(A)-1][r];
  cout << (ans == n ? "YES" : "NO") << endl;
}
