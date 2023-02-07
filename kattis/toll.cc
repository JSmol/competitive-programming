#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

template<typename T>
struct segment {
  // initialize tree with size n, op: (T, T) -> (T), identity value and optional initial data.
  int n, d; T id; function<T(T, T)> op;
  vector<int> L, R;
  vector<T> S;
  int depth(int i) { return 31 - __builtin_clz(i); }
  segment(int n, T id, function<T(T, T)> op, const vector<T>& A = {}) : n(n), d(depth(n) + (n != 1 << depth(n))), 
  id(id), op(op), L(1 << (d+1), 0), R(1 << (d+1), 0), S(1 << (d+1), id) {
    for (int i = 0; i <= d; i++)
      for (int j = (1 << i); j < (1 << (i+1)); j++)
        L[j] = (j % (1 << i)) * (1 << (d - i)),
        R[j] = L[j] + (1 << (d - i)) - 1;
    for (int i = 0; i < sz(A); i++) S[(1<<d)+i] = A[i];
    for (int i = (1 << d) - 1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }
  // query range op(A[l], ... , A[r]).
  T query(int l, int r, int i = 1) {
    if (r < l) return id;
    if (L[i] == l and R[i] == r) return S[i];
    else return op(query(l, min(r, R[2*i]), 2*i), query(max(l, L[2*i+1]), r, 2*i+1));
  }
};

int k, n, m, q;
const int inf = 1 << 28;
int main() {
  cin >> k >> n >> m >> q;
  
  // identity matrix is a special matrix with all entries -1
  const vector<vector<int>> id(k, vector<int>(k, -1));

  // initialize distances to inf
  vector<vector<vector<int>>> A((n+k-1)/k-1, vector<vector<int>>(k, vector<int>(k, inf)));
  for (int i = 0, a, b, c; i < m; i++) {
    cin >> a >> b >> c;
    A[a/k][a%k][b%k] = c;
  }
  
  // declare segment tree
  segment<vector<vector<int>>> st((n+k-1)/k-1, id, [&] (const auto& a, const auto& b) {
    if (a == id) return b; else if (b == id) return a; // handle seg-tree edge case
    vector<vector<int>> r(k, vector<int>(k, inf)); // compute distance matrix
    for (int l = 0; l < k; l++)
      for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
          r[i][j] = min(r[i][j], a[i][l] + b[l][j]);
    return r;
  }, A);

  for (int i = 0, a, b; i < q; i++) {
    cin >> a >> b;
    auto r = st.query(a/k, b/k-1);
    int ans = r[a%k][b%k];
    cout << (ans == inf ? -1 : ans) << endl;
  }
}

