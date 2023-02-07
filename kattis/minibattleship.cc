#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
typedef long double ld;
typedef long long ll;

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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  vector<vector<char>> A(n, vector<char>(n));
  for (auto& a : A) for (auto& x : a) cin >> x;
  vector<int> X(k);
  for (auto& x : X) cin >> x;

  vector<vector<int>> g(n, vector<int>(n));

  auto good = [&] () {
    for (int i = 0; i < n; i++) for(int j = 0; j < n; j++) if (A[i][j] == 'O' and !g[i][j]) return 0;
    return 1;
  };

  auto bounds = [&] (int i, int j) {
    return 0 <= i and i < n and 0 <= j and j < n;
  };

  auto rm = [&] (int x, int i, int j, int p) {
    if (p) {
      for (int l = 0; l < X[x]; l++) g[i+l][j] = 0;
    } else {
      for (int l = 0; l < X[x]; l++) g[i][j+l] = 0;
    }
  };

  auto can = [&] (int x, int i, int j, int p) {
    if (p) {
      for (int l = 0; l < X[x]; l++) {
        if (!bounds(i+l, j)) return 0;
        if (A[i+l][j] == 'X') return 0;
        if (g[i+l][j]) return 0;
      }

      for (int l = 0; l < X[x]; l++) g[i+l][j] = 1;
      return 1;
    } else {
      for (int l = 0; l < X[x]; l++) {
        if (!bounds(i, j+l)) return 0;
        if (A[i][j+l] == 'X') return 0;
        if (g[i][j+l]) return 0;
      }

      for (int l = 0; l < X[x]; l++) g[i][j+l] = 1;
      return 1;
    }
  };

  function<int(int)> f = [&] (int x) {
    if (x == k) return good();
    int ans = 0;
    for (int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      if (can(x, i, j, 0)) {
        ans += f(x+1);
        rm(x, i, j, 0);
      }

      if (X[x] != 1 and can(x, i, j, 1)) {
        ans += f(x+1);
        rm(x, i, j, 1);
      }
    }

    return ans;
  };

  cout << f(0) << endl;
} 

