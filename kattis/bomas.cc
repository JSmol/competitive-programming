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

/*  Non-Intersecting Nested Circle Hierarchy tree (root is n)
 *  A[i] = decendants of circle i
 */

typedef long long ll;
const ll inf = 1ll << 30;

template<typename T>
T sqr(T x) { return x*x; }
template<typename T>
T dist2(const pair<T, T>& a, const pair<T, T>& b) { return sqr(a.fst - b.fst) + sqr(a.snd - b.snd); }

template<typename T>
struct semicircle {
  T x, y, r; int p, i;
  bool operator<(const semicircle& b) const {
    if (b.p) {
      if (dist2(mp(x, y), mp(b.x, b.y)) < sqr(b.r)) return 0;
      else return y < b.y;
    } else {
      if (dist2(mp(x, y), mp(b.x, b.y)) < sqr(b.r)) return 1;
      else return y < b.y;
    }
  }
};

template<typename T> ostream& operator<<(ostream& o, const semicircle<T>& x) { o << "(" << x.x << ", " << x.y << ", " << x.r << ", " << x.i << ")"; return o; }

template<typename T>
vector<vector<int>> build(vector<pair<pair<T, T>, T>>& C, int n) {
  C.push_back({ { 0, 0 }, inf });
  vector<int> L(n), R(n);
  iota(all(L), 0); iota(all(R), 0);
  sort(all(L), [&] (int i, int j) { return C[i].fst.fst - C[i].snd < C[j].fst.fst - C[j].snd; });
  sort(all(R), [&] (int i, int j) { return C[i].fst.fst + C[i].snd < C[j].fst.fst + C[j].snd; });

  vector<int> P(n+1, -1);
  vector<vector<int>> A(n + 1);
  multiset<semicircle<T>> S = { { 0, 0, inf, 0, n }, { 0, 0, inf, 1, n } };
  for (int i = 0, j = 0, idx; i < n or j < n; ) {
    if (i == n or j == n) idx = (i < j ? L[i++] : R[j++]);
    else idx = (C[L[i]].fst.fst - C[L[i]].snd <= C[R[j]].fst.fst + C[R[j]].snd ? L[i++] : R[j++]);
    auto [c, r] = C[idx];
    if (P[idx] == -1) {
      auto x = *S.upper_bound({ c.fst - r, c.snd, r, 1, idx });
      if (dist2(c, C[x.i].fst) <= sqr(C[x.i].snd)) P[idx] = x.i, A[x.i].push_back(idx);
      else P[idx] = P[x.i], A[P[x.i]].push_back(idx);
      S.insert({ c.fst, c.snd, r, 0, idx });
      S.insert({ c.fst, c.snd, r, 1, idx });
    } else {
      S.erase({ c.fst, c.snd, r, 0, idx });
      S.erase({ c.fst, c.snd, r, 1, idx });
    }
  }

  return A;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<pair<pair<ll, ll>, ll>> C(n+q);
  for (int i = 0; i < n+q; i++) {
    cin >> C[i].fst.fst >> C[i].fst.snd >> C[i].snd;
  }

  auto A = build(C, n+q);
  vector<vector<int>> dp(n+q+1, vector<int>(2, -1));
  vector<vector<int>> ans(n+q+1, vector<int>(2));
  function<int(int,int)> f = [&] (int v, int p) {
    int& x = dp[v][p];
    if (x != -1) return x;

    x = 0;
    if (v < n) {
      for (auto& a : A[v]) x += f(a, 0);
      if (!p) {
        int z = 1;
        for (auto& a : A[v]) z += f(a, 1);
        x = max(x, z);
      }
    } else { // compute ans...
      int& w = ans[v][p];
      for (auto& a : A[v]) w += f(a, 0);
      if (!p) {
        int z = 1;
        for (auto& a : A[v]) z += f(a, 1);
        w = max(w, z);
      }
      
      // resume dp...
      for (auto& a : A[v]) x += f(a, p);
    }

    return x;
  };

  f(n+q, 0);
  for (int i = 0; i < q; i++)
    cout << max(ans[n+i][0], ans[n+i][1]) << endl;
}

