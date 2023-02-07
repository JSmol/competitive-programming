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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, n; cin >> m >> n;
  vector<vector<int>> A(m, vector<int>(n, 0));
  for (auto& a : A)
    for (auto& x : a) cin >> x;

  for (int i = m-2; i >= 0; i--) {
    for (int j = n-2; j >= 0; j--) {
      if (!A[i][j])
        A[i][j] = min(A[i+1][j], A[i][j+1]) - 1;
    }
  }

  int p = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n-1; j++)
      if (A[i][j] >= A[i][j+1]) p = 1;
  }

  for (int j = 0; j < n; j++)
    for (int i = 0; i < m-1; i++) {
      if (A[i][j] >= A[i+1][j]) p = 1;
  }

  int sum = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      sum += A[i][j];
    }
  }
  
  if (p) cout << -1 << endl;
  else cout << sum << endl;
}

