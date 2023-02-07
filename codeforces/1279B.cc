#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
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

typedef long long ll;
struct fenwick {
  int n; vector<ll> A;
  fenwick(int n) : n(n+1), A(n+1) { }
  void add(int i, int v) { while (i < n) A[i] += v, i += i & -i; } 
  ll query(int i) { ll s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (auto& a : A) cin >> a;

    fenwick X(n);
    for (int i = 0; i < n; i++) {
      X.add(i+1, A[i]);
    }

    int l = 1; int h = n;
    while (h-l > 2) {
      int m = (h+l)/2;
      if (X.query(m) < k) l = m;
      else h = m-1;
    }
    while (l <= n and X.query(l) <= k) l++;
    ll ans = l-1; int best = 0;

    for (int i = 0; i < n; i++) {
      X.add(i+1, -A[i]);

      l = 1; h = n;
      while (h-l > 2) {
        int m = (h+l)/2;
        if (X.query(m) <= k) l = m;
        else h = m-1;
      }
      while (l <= n and X.query(l) <= k) l++;

      if (ans < l-2) best = i+1, ans = l-2;
      X.add(i+1, A[i]);
    }

    cout << best << endl;
  }
}

