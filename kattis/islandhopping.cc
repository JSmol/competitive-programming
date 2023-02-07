#include <bits/stdc++.h>
using namespace std;

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

int n, t;
vector<edge> e;

void kruskal () {
  sort(begin(e), end(e), [](const edge& a, const edge& b) {
    return a.w < b.w;
  });

  double ans = 0;
  int i = 0;
  union_find uf{n};
  for (const auto& p : e) {
    if (i == n-1) break;

    if (uf.connected(p.a, p.b))
      continue;

    uf.merge(p.a, p.b);
    ans += p.w;
    i++;
  }
  cout << ans << '\n';
}

double dist (pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<pair<double, double>> A;

int main () {
  cin >> t;
  while (t--) {
    cin >> n;
    A.resize(n);
    for (auto& a : A) cin >> a.first >> a.second;

    e.resize(0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        edge a;
        a.a = i;
        a.b = j;
        a.w = dist(A[i], A[j]);
        e.push_back(a);
      }
    }
    kruskal();
  }
}
