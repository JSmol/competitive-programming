/*  Non-Intersecting Nested Circle Hierarchy tree (root is n)
 *  O(n log n) to build
 */

typedef long long ll;
const ll inf = 1ll << 60;

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
