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

typedef long long ll;
const ll inf = 1ll << 62;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<pair<int, ll>>> A(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w; u--; v--;
    A[u].push_back({v, w});
    A[v].push_back({u, w});
  }

  // dist, vert, 2x, 0x
  priority_queue<tuple<ll, int, int, int>> Q;
  Q.push({0, 0, 0, 0});
  // map<tuple<int, int, int>, ll> S;
  vector<vector<vector<ll>>> S(n, vector<vector<ll>>(2, vector<ll>(2, -inf)));
  while (!Q.empty()) {
    auto [d, v, f1, f2] = Q.top(); Q.pop();
    if (S[v][f1][f2] != -inf) continue;
    S[v][f1][f2] = -d;
    for (auto& [a, w] : A[v]) {
      Q.push({d - w, a, f1, f2});
      if (!f1) Q.push({d - 2*w, a, 1, f2});
      if (!f2) Q.push({d - 0, a, f1, 1});
      if (!f1 and !f2) Q.push({d - w, a, 1, 1});
    }
  }

  for (int i = 1; i < n; i++)
    cout << S[i][1][1] << " \n"[i == n-1];

}

