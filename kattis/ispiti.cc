#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
double time() { return double(clock()) / CLOCKS_PER_SEC; }

template<typename T>
struct segment {
  int n; T id; function<T(T, T)> op;
  vector<T> S;
  // initialize tree with size n, op: (T, T) -> (T), identity value and optional initial data.
  segment(int n, T id, function<T(T, T)> op, const vector<T>& A = {}) 
    : n(n), id(id), op(op), S(2*n, id) {
    for (int i = 0; i < sz(A); i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }
  // set A[x] to v
  void update(int x, T v) {
    for (S[x += n] = v; x > 1; x /= 2) 
      S[x/2] = op(S[x], S[x^1]);
  }
  // query range op(A[l], ... , A[r-1]).
  T query(int l, int r) {
    T ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> O, Q;
  vector<pair<int, int>> A;
  map<pair<int, int>, int> M;
  
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    O.push_back(c == 'D');
    if (c == 'D') {
      int x, y; cin >> y >> x;
      M[mp(x, y)] = sz(A);
      A.push_back({x, y});
    } else {
      int j; cin >> j;
      Q.push_back(j-1);
    }
  }

  vector<int> I(sz(A)); iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return A[i] < A[j]; });

  map<int, int> P, PI;
  for (int i = 0, j = 0, k = 0; i < sz(A); i = j) {
    while (j < sz(A) and A[I[i]].fst == A[I[j]].fst) j++;
    PI[k] = A[I[i]].fst;
    P[A[I[i]].fst] = k++;
  }

  vector<set<int>> X(sz(P));
  segment<int> st(1 << 18, 0, [] (int a, int b) { return max(a, b); });

  /*
  for (auto [x, y] : A) {
    X[P[x]].insert(y);
    st.update(P[x], *rbegin(X[P[x]]));
  }
  */

  auto f = [&] (int l, int h, int x) {

    while (h-l > 1) {
      int m = (h+l) / 2;
      if (st.query(l, m) >= x) {
        h = m;
      } else {
        l = m;
      }
    }

    while (l < sz(P) and st.query(l, l+1) < x) l++;
    return l;
  };

  for (int i = 0, j = 0, k = 0; k < sz(O); k++) {
    if (O[k]) {
      auto [x, y] = A[i++];
      X[P[x]].insert(y);
      st.update(P[x], *rbegin(X[P[x]]));
    } else {
      auto idx1 = Q[j++];
      auto [x, y] = A[idx1];
      auto lb = X[P[x]].lower_bound(y+1);
      if (lb != end(X[P[x]])) {
        cout << M[mp(x, *lb)] + 1 << endl;
      } else {
        int l = f(P[x]+1, sz(P), y);
        if (l < sz(X)) {
          auto ub = X[l].upper_bound(y-1);
          cout << M[mp(PI[l], *ub)] + 1 << endl;
        } else {
          cout << "NE" << endl;
        }
      }
    }
  }
}

