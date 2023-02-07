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

int f(vector<pair<int, string>> A, int n, int m, char x, char y) {
  int b = 0;
  for (int i = 0; i < m; i++) {
    if (A[i].snd.find(x) < A[i].snd.find(y)) b += A[i].fst;
    else b -= A[i].fst;
  }

  return (b > 0 ? 1 : 0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<pair<int, string>> A(m);
  for (auto& a : A) cin >> a.fst >> a.snd;

  vector<vector<int>> g(n, vector<int>(n));
  for (char i = 'A'; i < 'A' + n; i++) {
    for (char j = 'A'; j < 'A' + n; j++) {
      if (i != j) g[i - 'A'][j - 'A'] = f(A, n, m, i, j);
    }
  }

  vector<int> V(n);
  function<int(int)> h = [&] (int v) { 
    V[v] = 1; int x = 1;
    for (int i = 0; i < n; i++) {
      if (!V[i] and g[v][i]) {
        x += h(i);
      }
    }
    return x;
  };

  for (int i = 0; i < n; i++) {
    V.assign(n, 0);
    cout << char('A' + i) << ": ";
    if (h(i) == n) cout << "can win" << endl;
    else cout << "can't win" << endl;
  }
}

