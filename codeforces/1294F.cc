#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define emplace emplace_back

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

int n;
vector<vector<int>> A;

pair<int, int> f(int v, int p, int d) {
  if (p != -1 and sz(A[v]) == 1) return { d, v };
  pair<int, int> ans = {-1, -1};
  for (auto& a : A[v]) {
    if (a != p) {
      ans = max(ans, f(a, v, d+1));
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, {});
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--; v--;
    A[u].emplace(v);
    A[v].emplace(u);
  }

  int v1 = f(0, -1, 0).snd;
  auto [di, v2] = f(v1, -1, 0);
  queue<pair<int, int>> Q;
  function<int(int, int)> g = [&] (int v, int p) {
    if (v == v2) {
      Q.push({v2, 0});
      return 1;
    }
    int x = 0;
    for (auto& a : A[v]) {
      if (a != p) {
        x |= g(a, v);
      }
    }

    if (x) Q.push({v, 0});
    return x;
  };

  g(v1, -1);
  pair<int, int> ans = {-1, -1};
  vector<int> V(n);
  while (!Q.empty()) {
    auto [v, d] = Q.front(); Q.pop();
    if (V[v]) continue;
    V[v] = 1;
    if (v != v1 and v != v2) ans = max(ans, mp(d, v));
    for (auto& a : A[v]) Q.push({a, d+1});
  }

  cout << di + ans.fst << endl;
  cout << v1+1 << ' ' << v2+1 << ' ' << ans.snd+1 << endl;
}
