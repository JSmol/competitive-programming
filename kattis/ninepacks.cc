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

int inf = 1 << 20;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h; cin >> h;
  vector<int> H(h);
  for (auto& x : H) cin >> x;
  int b; cin >> b;
  vector<int> B(b);
  for (auto& x : B) cin >> x;

  if (b == 0 or h == 0) {
    cout << "impossible" << endl;
    return 0;
  }

  int N = 100*1000 + 1;
  vector<vector<int>> f(h, vector<int>(N, inf));
  f[0][0] = 0;
  for (int i = 0; i < h; i++) {
    for (int s = 0; s < N; s++) {
      if (s - H[i] >= 0) {
        if (i > 0)
          f[i][s] = min({
              f[i-1][s-H[i]] + 1,
              f[i-1][s]
            });
        else
          f[i][s] = (s-H[i] == 0 ? 1 : inf);
      } else {
        if (i > 0)
          f[i][s] = f[i-1][s];
      }
    }
  }

  vector<vector<int>> g(b, vector<int>(N, inf));
  g[0][0] = 0;
  for (int i = 0; i < b; i++) {
    for (int s = 0; s < N; s++) {
      if (s - B[i] >= 0) {
        if (i > 0)
          g[i][s] = min({
              g[i-1][s-B[i]] + 1,
              g[i-1][s]
            });
        else
          g[i][s] = (s-B[i] == 0 ? 1 : inf);
      } else {
        if (i > 0)
          g[i][s] = g[i-1][s];
      }
    }
  }

  // for (int i = 0; i < h; i++) debug(f[i])
  // for (int i = 0; i < b; i++) debug(g[i])

  int ans = inf;
  for (int i = 1; i < N; i++)
    ans = min(ans, f[h-1][i] + g[b-1][i]);

  if (ans == inf) cout << "impossible" << endl;
  else cout << ans << endl;
}

