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

typedef long long ll;

// add(i, v) = add v to A[i] | i in [1, n]
// query(i) = range sum [1, i]
// lower_bound(x) = i such that query(i) < x and query(i+1) >= x
struct fenwick {
  int n; vector<ll> A;
  fenwick(int n) : n(n+1), A(n+1) { }
  void add(int i, ll v) { while (i < n) A[i] += v, i += i & -i; } 
  ll query(int i) { ll s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
  int lower_bound(int x) {
    int i = 0; // NOTE: A[i] >= 0. for this to make sense!
    for (int b = 1 << (31 - __builtin_clz(n)); b; b /= 2)
      if (i+b < n and x > A[i+b]) x -=  A[i+b], i += b;
    return i;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a;

  vector<int> X(n);
  for (auto& x : X) cin >> x;

  vector<int> I(n);
  iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return A[i] < A[j]; });

  auto Y = X;
  sort(all(Y));

  fenwick f(n), q(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(all(Y), X[I[i]]) - begin(Y);
    long long s = q.query(pos + 1);
    ans += s * A[I[i]] - f.query(pos + 1);
    f.add(pos + 1, A[I[i]]);
    q.add(pos + 1, 1);
  }

  cout << ans << endl;
}

