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

int n, m, x, y;
vector<vector<int>> A;

int l = 0;
vector<int> L, V;

long long f(int v, int p, bool q, bool w) {
  if (V[v]) {
    if (q) {
      // debug(q);
      // debug(v);
      if (w) {
        if (L[v] < L[x]) return -1;
      } else {
        if (L[v] < L[y]) return -1;
      }
    }
    return 0;
  }

 // / V[v] = 1;
  L[v] = l++;
  long long s = (q and !w) or (q and w);
  // if (s) debug(v);
  if (!w and v == y) q = 1;
  if (w and v == x) q = 1;

  int rv = 0;
  for (auto& a : A[v]) {
    if (a == p) continue;

    if ((w and v == x) or (!w and v == y)) {
      long long r = f(a, v, q, w);
      if (r == -1) continue;
      else s += r;
      // debug(r);
    } else {
      long long r = f(a, v, q, w);
      if (r == -1) rv = -1;
      else s += r;
    }

    if (L[a] < L[v]) L[v] = L[a];
  }

  if (rv == -1) return rv;
  return s;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n >> m >> x >> y; x--; y--;
    A.assign(n, {});
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v; u--; v--;
      A[u].push_back(v);
      A[v].push_back(u);
    }

    l = 1;
    V.assign(n, 0);
    L.assign(n, 0);
    long long ans1 = f(x, -1, 0, 0);
    // debug(L);
    // debug(ans1);

    l = 1;
    V.assign(n, 0);
    L.assign(n, 0);
    long long ans2 = f(y, -1, 0, 1);
    // debug(L);
    // debug(ans2);

    if (ans1 > 0 and ans2 > 0) cout << ans1 * ans2 << endl;
    else cout << 0 << endl;
  }
}

