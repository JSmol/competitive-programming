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

struct segment {

  const int id1 = (1 << 30);

  int op1(int a, int b) {
    return min(a, b);
  }

  const int id2 = -(1 << 30);

  int op2(int a, int b) {
    return max(a, b);
  }

  int depth(int i) {
    return 31 - __builtin_clz(i);
  }

  void apply(int i, int v) {
    S1[i] += v;
    S2[i] += v;
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
  vector<int> S1, S2, D, L, R;
  segment(vector<int> A, int n) : n(n), d(depth(n) + 1) {
    L.assign(1 << (d+1), 0); R.assign(1 << (d+1), 0);
    for (int i = 0; i <= d; i++)
      for (int j = (1 << i); j < (1 << (i+1)); j++)
        L[j] = (j % (1 << i)) * (1 << (d - i)),
        R[j] = L[j] + (1 << (d - i)) - 1;

    D.assign(1 << (d+1), 0);
    S1.assign(1 << (d+1), id1);
    S2.assign(1 << (d+1), id2);
    for (int i = 0; i < n; i++) S1[(1<<d)+i] = A[i];
    for (int i = (1 << d) - 1; i > 0; i--) S1[i] = op1(S1[2*i], S1[2*i+1]);
    for (int i = 0; i < n; i++) S2[(1<<d)+i] = A[i];
    for (int i = (1 << d) - 1; i > 0; i--) S2[i] = op2(S2[2*i], S2[2*i+1]);
  }

  void add(int l, int r, int v, int i = 1) {
    if (r < l) return;
    if (L[i] == l and R[i] == r) apply(i, v);
    else {
      prop(i);
      add(l, min(r, R[2*i]), v, 2*i); 
      add(max(l, L[2*i+1]), r, v, 2*i+1);
      S1[i] = op1(S1[2*i], S1[2*i+1]);
      S2[i] = op2(S2[2*i], S2[2*i+1]);
    }
  }

  int querymin(int l, int r, int i = 1) {
    if (r < l) return id1;
    if (L[i] == l and R[i] == r) return S1[i];
    else {
      prop(i);
      return op1(querymin(l, min(r, R[2*i]), 2*i), querymin(max(l, L[2*i+1]), r, 2*i+1));
    }
  }

  int querymax(int l, int r, int i = 1) {
    if (r < l) return id2;
    if (L[i] == l and R[i] == r) return S2[i];
    else {
      prop(i);
      return op2(querymax(l, min(r, R[2*i]), 2*i), querymax(max(l, L[2*i+1]), r, 2*i+1));
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  const int m = (1<<20)-1;
  int n;
  string s;
  cin >> n >> s;

  string t(m, ' '); else
  vector<int> A(m, 0);
  segment st(A, m);

  int c = 0;
  for (auto& x : s) {
    if (x == 'R') {
      c++;
    } else
    if (x == 'L') {
      c -= (c ? 1 : 0);
    } else
    if (x == '(') {
      if (t[c] == x) {
      } else 
      if (t[c] == ')') {
        st.add(c, m, 2);
      } else
      if (t[c] != '(') {
        st.add(c, m, 1);
      }
      t[c] = x;
    } else 
    if (x == ')') {
      if (t[c] == x) {
      } else 
      if (t[c] == '(') {
        st.add(c, m, -2);
      } else 
      if (t[c] != '(') {
        st.add(c, m, -1);
      }
      t[c] = x;
    } else {
      if (t[c] == '(') {
        st.add(c, m, -1);
      } else
      if (t[c] == ')') {
        st.add(c, m, 1);
      } else {
      }
      t[c] = x;
    }

    // for (int i = 0; i < m; i++) st.add(i, i, 0);
    // debug(t);
    // debug(st.querymax(0, m));
    // debug(st.querymax(m-1, m));
    // debug(st.querymin(0, m));
    // debug(st.S1);

    int ans = -1;
    if (st.querymax(m-1, m) == 0 and st.querymin(0, m) >= 0) {
      ans = st.querymax(0, m);
    }

    cout << ans << ' ';
  }

  cout << endl;
}

