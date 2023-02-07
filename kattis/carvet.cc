#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
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

int A[256][256];
int V[256][256];
int out[256*256];
int o = 0;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 256; i++) for (int j = 0; j < 256; j++) A[i][j] = -2;
  int m, n; cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) cin >> A[i][j];
  }

  int x, y; cin >> x >> y;

  int ans = -1;
  while (true) {
    if (A[x][y] == -2) {
      ans = 0;
      break;
    }

    if (A[x][y] == -1) {
      ans = 1;
      break;
    }

    if (V[x][y]) {
      ans = 0;
      break;
    }

    V[x][y] = 1;
    assert(o < 256*256);
    if (A[x][y] == A[x+1][y]) out[o++] = A[x][y], x += 2;
    if (A[x][y] == A[x-1][y]) out[o++] = A[x][y], x -= 2;
    if (A[x][y] == A[x][y+1]) out[o++] = A[x][y], y += 2;
    if (A[x][y] == A[x][y-1]) out[o++] = A[x][y], y -= 2;
  }

  if (ans) {
    for (int i = o-1; i >= 0; i--) cout << out[i] << ' ';
    cout << endl;
  } else cout << "impossible" << endl;
}

