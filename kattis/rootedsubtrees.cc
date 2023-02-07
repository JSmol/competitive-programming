#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& a : x)
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

ll nck(ll n, ll k) { ll r = 1; for (ll i = 0; i < k; i++) { r *= (n - i); r /= (i + 1); } return r; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<vector<int>> A(n);
  rep(i, 0, n-1) {
    int a, b; cin >> a >> b; a--; b--;
    A[a].push_back(b);
    A[b].push_back(a);
  }

  vector<int> D(n, -1);
  vector<vector<int>> t(n, vector<int>(20, -1));
  function<void(int, int, int)> f = [&] (int v, int p, int d) {
    t[v][0] = p;
    D[v] = d;
    trav(a, A[v]) {
      if (a == p) continue;
      f(a, v, d+1);
    }
  };

  f(0, -1, 0);
  rep(j, 1, 20) {
    rep(i, 0, n) {
      if (t[i][j-1] != -1) t[i][j] = t[t[i][j-1]][j-1];
    }
  }

  function<int(int, int)> lca = [&] (int a, int b) {
    if (D[a] > D[b]) swap(a, b);

    for (int j = 18; j >= 0; j--) {
      if (t[b][j] != -1 and D[a] <= D[t[b][j]]) b = t[b][j];
    }

    assert(D[a] == D[b]);
    if (a == b) return a;

    for (int j = 18; j >= 0; j--) {
      if (t[b][j] != t[a][j]) {
        b = t[b][j]; a = t[a][j];
      }
    }

    assert(t[a][0] == t[b][0]);
    return t[a][0];
  };

  rep(i, 0, q) {
    int a, b; cin >> a >> b; a--; b--;
    int c = lca(a, b);
    int d = (D[a] + D[b]) - 2*D[c];
    cout << n + nck(d+1, 2) << endl;
  }
} 

