#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T> struct DynamicHull {
  struct Line {
    typedef typename multiset<Line>::iterator It;
    T a, b; mutable It me, endit, none;
    Line(T a, T b, It endit) : a(a), b(b), endit(endit) {}
    bool operator<(const Line& rhs) const {
      if (rhs.endit != none) return a < rhs.a;
      if (next(me) == endit) return 0;
      return (b - next(me)->b) < (next(me)->a - a) * rhs.a;
    }
  };
  multiset<Line> lines;
  void add(T a, T b) {
    auto bad = [&](auto y) {
      auto z = next(y);
      if (y == lines.begin()) {
        if (z == lines.end()) return false;
        return y->a == z->a and z->b >= y->b;
      }
      auto x = prev(y);
      if (z == lines.end()) return y->a == x->a and x->b >= y->b;
      return (long double) (x->b-y->b) * (z->a-y->a) >= (long double) (y->b-z->b) * (y->a-x->a);
    };
    auto it = lines.emplace(a, b, lines.end()); it->me = it;
    if (bad(it)) { lines.erase(it); return; }
    while (next(it) != lines.end() and bad(next(it))) lines.erase(next(it));
    while (it != lines.begin() and bad(prev(it))) lines.erase(prev(it));
  }
  T query(T x) {
    auto it = lines.lower_bound(Line{x, 0, {}});
    return it->a * x + it->b;
  }
};

typedef long long ll;
int n;
vector<ll> ans;
vector<int> A, B, W;
vector<bool> V;
vector<vector<int>> X;

int calc(int v) {
  if (W[v]) return 0;
  W[v] = 1;
  for (auto& a : X[v]) W[v] += calc(a);
  return W[v];
}

void f(int v, DynamicHull<ll>& D) {
  if (v != 0 and sz(X[v]) == 1) {
    D.add(-B[v], 0);
    return;
  }

  if (V[v]) return;
  V[v] = 1;

  sort(all(X[v]), [&] (int a, int b) { return W[a] > W[b]; });
  f(X[v][0], D);

  for (int i = 1; i < sz(X[v]); i++) {
    DynamicHull<ll> C;
    f(X[v][i], C);
    for (auto& line : C.lines) {
      D.add(line.a, line.b);
    }
  }

  ll y = D.query(A[v]);
  ans[v] = y;
  D.add(-B[v], y);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  B.assign(n, 0);
  for (auto& b : B) cin >> b;
  X.assign(n, {});
  for (int i = 0, u, v; i < n-1; i++) {
    cin >> u >> v; u--; v--;
    X[u].push_back(v);
    X[v].push_back(u);
  }

  ans.assign(n, 0);
  V.assign(n, 0);
  W.assign(n, 0);
  calc(0);

  DynamicHull<ll> D;
  f(0, D);

  for (auto& a : ans) cout << -a << ' ';
  cout << endl;
}

