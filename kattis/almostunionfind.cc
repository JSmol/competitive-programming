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
struct UF {
  int n; vector<ll> A, cnt, sum;
  UF (int n) : n(n), A(n), cnt(n, 1), sum(n, 0) {
    iota(all(A), 0);
    iota(all(sum), 1);
  }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) {
    if (!connected(a, b)) {
      cnt[find(a)] += cnt[find(b)];
      sum[find(a)] += sum[find(b)];
      cnt[find(b)] = 0;
      sum[find(b)] = 0;
      A[find(b)] = find(a); 
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    int x = n;
    vector<int> A(n);
    iota(all(A), 0);
    UF uf(n+m+5);
    auto& cnt = uf.cnt;
    auto& sum = uf.sum;
    for (int i = 0, q, a, b; i < m; i++) {
      cin >> q;
      if (q == 1) {
        cin >> a >> b; a--; b--;
        if (!uf.connected(A[a], A[b])) {
          uf.merge(A[a], A[b]);
        }
      }
      if (q == 2) {
        cin >> a >> b; a--; b--;
        if (!uf.connected(A[a], A[b])) {
          cnt[uf.find(A[a])]--;
          sum[uf.find(A[a])] -= a+1;
          sum[x] = a+1;
          A[a] = x++;
          uf.merge(A[a], A[b]);
        }
      }
      if (q == 3) {
        cin >> a; a--;
        cout << cnt[uf.find(A[a])] << ' ' << sum[uf.find(A[a])] << endl;
      }
    }
  }
}

