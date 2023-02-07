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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

// segment tree with lazy prop, log(n) range query and range update. (modifiable version)
// st.update(l, r, v) -> apply(i, v) where i ranges in [l, r]
// st.query(l, r) -> compute op of range [l, r]
// think about non-commutative ops!!

struct segment {

  int id = 0; // op identity
  int n, d; // Delta type ? Node type ?
  vector<int> L, R, D; vector<int> S;

  int op(int a, int b) {
    return a + b;
  }

  void apply(int i) { // apply change v to node i
    S[i] = R[i] - L[i] + 1;
    D[i] = 1;
  }

  void prop(int i) {
    if (depth(i) != d and D[i]) { // if not leaf and positive delta
      apply(2*i+1); // apply change to children & reset delta
      apply(2*i);
      D[i] = 0;
    }
  }

  // --- shouldn't have to modify below here ---
  // initialize tree with size n, and initial data.
  int depth(int i) { return 31 - __builtin_clz(i); }
  segment(int n, const vector<int>& A = {}) : n(n), d(depth(n) + (n != 1 << depth(n))), 
  L(1 << (d+1), 0), R(1 << (d+1), 0), D(1 << (d+1), 0), S(1 << (d+1), id) {
    for (int i = 0; i <= d; i++)
      for (int j = (1 << i); j < (1 << (i+1)); j++)
        L[j] = (j % (1 << i)) * (1 << (d - i)),
        R[j] = L[j] + (1 << (d - i)) - 1;
    for (int i = 0; i < sz(A); i++) S[(1<<d)+i] = A[i];
    for (int i = (1 << d) - 1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  // update range [l, r]
  void update(int l, int r, int i = 1) {
    if (r < l) return;
    if (L[i] == l and R[i] == r) apply(i);
    else {
      prop(i);
      update(l, min(r, R[2*i]), 2*i); 
      update(max(l, L[2*i+1]), r, 2*i+1);
      S[i] = op(S[2*i], S[2*i+1]);
    }
  }

  // query op in range [l, r]
  int query(int l, int r, int i = 1) {
    if (r < l) return id;
    if (L[i] == l and R[i] == r) return S[i];
    else {
      prop(i);
      return op(query(l, min(r, R[2*i]), 2*i), query(max(l, L[2*i+1]), r, 2*i+1));
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, n, k, t; cin >> m >> n >> k >> t;
  vector<int> a(m), l(k), r(k), d(k), I(k), J(m);
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> l[i] >> r[i] >> d[i];
  iota(all(I), 0); iota(all(J), 0);
  sort(all(I), [&] (int i, int j) { return d[i] < d[j]; });
  sort(all(J), [&] (int i, int j) { return a[i] > a[j]; });

  int ans = 0;
  segment st(n+1);
  for (int j = 0, i = k-1; j < m; j++) {
    int x = a[J[j]];
    while (i >= 0 and x < d[I[i]]) {
      st.update(l[I[i]], r[I[i]]);
      i--;
    }

    int q = st.query(0, n);
    if (2*q + n + 1 <= t) {
      ans = j + 1;
    }
  }

  // w h a t ?
  cout << ans << endl;
}

