#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

struct union_find {

  union_find (int size) {
    n = size;
    A = vector<int>(n);
    iota(begin(A), end(A), 0);
  }

  int find (int a) {
    return a == A[a] ? a : A[a] = find(A[a]);
  }

  bool connected (int a, int b) {
    return find(a) == find(b);
  }

  void merge (int a, int b) {
    A[find(b)] = find(a);
  }

  int n;
  vector<int> A;

};

struct edge {
  int a, b;
  double w;
};

vector<edge> E;

int n, m, f, p;
vector<pair<double, double>> A;

double dist(const pair<double, double>& a, const pair<double, double>& b) {
  return hypot(a.fst - b.fst, a.snd - b.snd);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> f >> p;

  A.assign(n, {});
  union_find uf{n};
  for (int i = 0; i < n; i++) {
    auto& a = A[i];
    cin >> a.fst >> a.snd;
    if (i < f) uf.merge(0, i);
  }

  m += f - 1;

  for (int i = 0, a, b; i < p; i++) {
    cin >> a >> b, a--, b--;
    if (!uf.connected(a, b))
      uf.merge(a, b),
      m++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++ ) {
      if (i != j)
        E.push_back({i, j, dist(A[i], A[j])});
    }
  }

  sort(begin(E), end(E), [](const edge& a, const edge& b) {
    return a.w < b.w;
  });

  double ans = 0;
  for (const auto& e : E) {
    if (m == n-1) break;

    if (uf.connected(e.a, e.b))
      continue;

    uf.merge(e.a, e.b);

    ans += e.w;
    m++;
  }

  cout << ans << endl;
 
}

