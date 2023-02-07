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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n[2], m[2];
  cin >> n[0] >> n[1] >> m[0] >> m[1];
  vector<vector<vector<int>>> A = { vector<vector<int>>(n[0]), vector<vector<int>>(n[1]) };
  for (int g : {0, 1}) {
    for (int i = 0, u, v; i < m[g]; i++) {
      cin >> u >> v; u--; v--;
      A[g][u].push_back(v);
    }
  }

  vector<vector<vector<int>>> dp = { vector<vector<int>>(n[0], vector<int>(2020, -1)), vector<vector<int>>(n[1], vector<int>(2020, -1)) };
  function<int(int, int, int)> f = [&] (int g, int v, int k) {
    if (k < 0) return 0;
    if (v == n[g]-1) return int(k == 0);

    int& x = dp[g][v][k];
    if (x != -1) return x;

    x = 0;
    for (auto& a : A[g][v]) {
      x |= f(g, a, k-1);
    }

    return x;
  };

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int k; cin >> k;
    int ans = 0;
    for (int j = 0; j <= k; j++) {
      ans |= (f(0, 0, j) & f(1, 0, k-j));
    }

    cout << (ans ? "Yes" : "No") << endl;
  }

}

