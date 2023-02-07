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

int n, m, k1, k2;
vector<vector<tuple<int, int, int>>> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k1 >> k2;
  A.assign(n, {});
  for (int i = 0, u, v, x, c; i < m; i++) {
    cin >> u >> v >> x >> c; u--; v--;
    A[u].push_back({v, x, c});
    A[v].push_back({u, x, c});
  } 

  long long ans = -1;
  int s, t; cin >> s >> t; s--; t--;
  map<tuple<int, int, int>, long long> D;
  priority_queue<tuple<long long, int, int, int>> Q;
  Q.push({0, s, 0, 0});
  while (!Q.empty()) {
    auto [d, v, a, b] = Q.top(); Q.pop();
    if (a > k1 or b > k2) continue;
    if (D.count({v, a, b})) continue;
    if (v == t and a == k1 and b == k2) { ans = -d; break; }

    D[{v, a, b}] = d;
    for (auto& p : A[v]) {
      auto [u, x, c] = p;
      Q.push({d - x, u, a + (c == 1), b + (c == 2)});
    }
  }

  cout << ans << endl;
}

