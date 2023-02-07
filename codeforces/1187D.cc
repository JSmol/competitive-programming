#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

// segment tree range query with point updates
struct segment {

  // id = 0 for add, +inf for min, -inf for max.
  const int id = 1 << 30;

  // choose appropriate op.
  int op(int a, int b) {
    return min(a, b);
  }

  int depth(int i) {
    return 31 - __builtin_clz(i);
  }

  int n, d;
  vector<int> S, L, R;
  segment(vector<int> A, int size) {

    d = depth(size);
    if (1 << d != size) d++;

    L.assign(1 << (d+1), 0);
    R.assign(1 << (d+1), 0);
    S.assign(1 << (d+1), 0);

    for (int i = 0; i <= d; i++) {
      for (int j = (1 << i); j < (1 << (i+1)); j++) {
        L[j] = (j % (1 << i)) * (1 << (d - i));
        R[j] = L[j] + (1 << (d - i)) - 1;
      }
    }

    n = 1 << d;
    for (int i = 0; i < size; i++) S[n+i] = A[i];
    for (int i = size; i < n; i++) S[n+i] = id;
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  // set A[k] to v
  void set(int k, int v, int i = 1) {
    if (k < L[i] or R[i] < k) return;
    if (L[i] == k and k == R[i]) S[i] = v;
    else {
      set(k, v, 2*i); 
      set(k, v, 2*i+1);
      S[i] = op(S[2*i], S[2*i+1]);
    }
  }

  // query range A[l], ... , A[r].
  int query(int l, int r, int i = 1) {
    if (r < l) return id;
    if (L[i] == l and R[i] == r) return S[i];
    else return op(query(l, min(r, R[2*i]), 2*i), query(max(l, L[2*i+1]), r, 2*i+1));
  }

};


const int inf = (1 << 30);
int t, n;
vector<int> A, B;
vector<set<int>> S;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;

    A.assign(n, 0);
    S.assign(n, {});
    for (int i = 0; i < n; i++) {
      cin >> A[i]; A[i]--;
      S[A[i]].insert(i);
    }

    B.assign(n, 0);
    for (auto& b : B) cin >> b, b--;

    segment st(A, n);

    bool ans = true;
    for (int i = 0; i < n; i++) {
      auto next = begin(S[B[i]]);
      if (next != end(S[B[i]])) {
        if (st.query(0, *next) >= B[i]) {
          st.set(*next, inf);
          S[B[i]].erase(next);
        } else {
          ans = false;
          break;
        }
      } else {
        ans = false;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}



