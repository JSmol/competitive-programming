#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

// segment tree with lazy prop
struct segment {

  const int id = (1 << 30);

  int op(int a, int b) {
    return min(a, b);
  }

  int depth(int i) {
    return 31 - __builtin_clz(i);
  }

  void apply(int i, int v) {
    S[i] += v;
    D[i] += v;
  }

  void prop(int i) {
    if (depth(i) != d and D[i]) {
      apply(2*i+1, D[i]);
      apply(2*i, D[i]);
      D[i] = 0;
    }
  }

  int n, d;
  vector<int> S, D, L, R;
  segment(vector<int> A, int n) : n(n), d(depth(n) + ((1 << depth(n)) != n)) {
    L.assign(1 << (d+1), 0); R.assign(1 << (d+1), 0);
    for (int i = 0; i <= d; i++)
      for (int j = (1 << i); j < (1 << (i+1)); j++)
        L[j] = (j % (1 << i)) * (1 << (d - i)),
        R[j] = L[j] + (1 << (d - i)) - 1;

    D.assign(1 << (d+1), 0);
    S.assign(1 << (d+1), id);
    for (int i = 0; i < n; i++) S[(1<<d)+i] = A[i];
    for (int i = (1 << d) - 1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  void add(int l, int r, int v, int i = 1) {
    if (r < l) return;
    if (L[i] == l and R[i] == r) apply(i, v);
    else {
      prop(i);
      add(l, min(r, R[2*i]), v, 2*i); 
      add(max(l, L[2*i+1]), r, v, 2*i+1);
      S[i] = op(S[2*i], S[2*i+1]);
    }
  }

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
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> A(n);
  for (auto& a : A) cin >> a;
  const int& r = A[0];
  
  vector<vector<int>> X(m);
  for (int i = 0, x; i < m; i++) {
    cin >> x;
    X[i].assign(x, 0);
    for (auto& a : X[i]) cin >> a;
  }

  vector<int> P(m+1, 0), M(m+1, 0);
  for (auto& a : A) P[0] += (a > r);
  M[0] = (n - P[0]) - sz(X[0]);

  for (int i = 1; i <= m; i++) {
    P[i] = P[i-1];
    for (auto& a : X[i-1]) P[i] += (a > r);
    M[i] = (n - P[i]) - (i == m ? 0 : sz(X[i]));
  }

  // debug(P);
  // debug(M);
  segment st (M, m+1);
  // debug(st.S);

  while (q--) {
    int i, j, x;
    cin >> i >> j >> x; i--; j--;
    if (X[i][j] < r and x > r) {
      // M[i+1] -> M[m] -= 1
      st.add(i+1, m, -1);
    }

    if (X[i][j] > r and x < r) {
      // M[i+1] -> M[m] += 1
      st.add(i+1, m, 1);
    }

    X[i][j] = x;

    int ans = st.query(0, m);
    // debug(st.S);
    // debug(ans);
    cout << (ans <= 0 ? 0 : 1) << endl;
  }
}

