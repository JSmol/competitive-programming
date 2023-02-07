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

struct fenwick {
  int n; vector<int> A;
  fenwick(int n) : n(n+1), A(n+1) { }
  void add(int i, int v) { while (i < n) A[i] += v, i += i & -i; } 
  int query(int i) { int s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n+1), C(n+1);
    for (int i = 1; i <= n; i++) cin >> A[i], C[A[i]] = i;

    string ans(n, '0');
    ans[0] = '1';
    int l = C[1], h = C[1];
    fenwick f(n+1);
    f.add(l, 1);
    for (int i = 2; i <= n; i++) {
      f.add(C[i], 1);
      if (C[i] < l) l = C[i];
      if (C[i] > h) h = C[i];
      int s = f.query(h) - (l-1 ? f.query(l-1) : 0);

      if (s == h - l + 1 and s == i) {
        ans[i-1] = '1';
      }
    }
    cout << ans << endl;
  }
}

