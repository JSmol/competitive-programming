#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define mp make_pair

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T>
struct segment {
  int n; T id; function<T(T, T)> op;
  vector<T> S;
  segment(int n, T id, function<T(T, T)> op, const vector<T>& A = {}) 
    : n(n), id(id), op(op), S(2*n, id) {
    for (int i = 0; i < sz(A); i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }
  // query range A[l], ... , A[r-1].
  T query(int l, int r) {
    T ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};

bool bounds(int i, int n) {
  return i >= 0 and i < n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> x(n), y(n), I(n), J(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    I[i] = J[i] = i;
  }

  sort(all(I), [&] (int i, int j) { return x[i] < x[j]; });
  sort(all(J), [&] (int i, int j) { return y[i] < y[j]; });

  // l, ... , r -> min/max and 2min/2max
  const int inf = (1 << 31) - 1;
  debug(inf);
  vector<pair<int, int>> A(n);

  for (int i = 0; i < n; i++) A[I[i]] = { i, inf };
  segment<pair<int, int>> xstmn(n, {inf, inf}, [] (auto a, auto b) {
    vector<int> X = {a.fst, a.snd, b.fst, b.snd};
    sort(all(X));
    return mp(X[0], X[1]);
  }, A);
  for (int i = 0; i < n; i++) A[I[i]] = { i, -inf };
  segment<pair<int, int>> xstmx(n, {-inf, -inf}, [] (auto a, auto b) {
    vector<int> X = {a.fst, a.snd, b.fst, b.snd};
    sort(all(X));
    return mp(X[3], X[2]);
  }, A);
  for (int i = 0; i < n; i++) A[J[i]] = { i, inf };
  segment<pair<int, int>> ystmn(n, {inf, inf}, [] (auto a, auto b) {
    vector<int> X = {a.fst, a.snd, b.fst, b.snd};
    sort(all(X));
    return mp(X[0], X[1]);
  }, A);
  for (int i = 0; i < n; i++) A[J[i]] = { i, -inf };
  segment<pair<int, int>> ystmx(n, {-inf, -inf}, [] (auto a, auto b) {
    vector<int> X = {a.fst, a.snd, b.fst, b.snd};
    sort(all(X));
    return mp(X[3], X[2]);
  }, A);

  for (int i = 0, l, r; i < q; i++) {
    cin >> l >> r; l--; r--;
    auto [xmin1, xmin2] = xstmn.query(l, r+1);
    auto [xmax1, xmax2] = xstmx.query(l, r+1);
    auto [ymin1, ymin2] = ystmn.query(l, r+1);
    auto [ymax1, ymax2] = ystmx.query(l, r+1);

    int ans = inf;
    set<int> points = { I[xmin1], I[xmin2], I[xmax1], I[xmax2], J[ymin1], J[ymin2], J[ymax1], J[ymax2] };

    for (auto& r : points) {
      int minx = inf;
      int maxx = -inf;
      int miny = inf;
      int maxy = -inf;
      for (auto& p : points) {
        if (r == p) continue;
        minx = min(minx, x[p]);
        maxx = max(maxx, x[p]);
        miny = min(miny, y[p]);
        maxy = max(maxy, y[p]);
      }
      ans = min(ans, max(maxx - minx, maxy - miny));
    }

    cout << ans << endl;
  }
}

