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

struct UF {
  int n; vector<int> A, size;
  UF (int n) : n(n), A(n), size(n, 1) { iota(all(A), 0); }
  int find(int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge(int a, int b) {
    if (connected(a, b)) return;
    size[A[find(a)]] += size[A[find(b)]];
    size[A[find(b)]] = 0;
    A[find(b)] = find(a);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int ans = 0;
  UF uf(505050);
  auto& size = uf.size;
  for (int i = 0, k = 0; i < n; i++) {
    cin >> k;
    vector<int> A(k);
    for (int j = 0; j < k; j++) cin >> A[j];
    
    map<int, int> M;
    for (int j = 0; j < k; j++) {
      M[uf.find(A[j])]++;
    }

    bool p = 1;
    for (int j = 0; j < k; j++) {
      if (M[uf.find(A[j])] != size[uf.find(A[j])]) p = 0;
    }

    // debug(M);
    if (p) { ans ++;
      for (int j = 1; j < k; j++) {
        uf.merge(A[j], A[j-1]);
      }
    }
    
    // for (int i = 1; i <= 5; i++) {
      // cerr << i << ": " << uf.find(i) << ' ' << size[uf.find(i)] << endl;
    // }

    // cerr << endl;
  }
  cout << ans << endl;
}

