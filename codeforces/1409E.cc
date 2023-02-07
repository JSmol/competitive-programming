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

int n, k;
vector<pair<int, int>> A;
vector<int> X;
vector<vector<int>> dp;
int f(int i, int p) {
  if (i == n) return 0;
  if (p == 2) return 0;

  int& x = dp[i][p];
  if (x != -1) return x;
  
  int ub = upper_bound(all(A), mp(A[i].fst+k, 1 << 30)) - begin(A) - 1;
  int s = X[ub] - (i ? X[i-1] : 0);

  x = max(f(i+1, p), s + f(ub+1, p+1));
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int C = 1; C <= T; C++) {
    int m; cin >> m >> k;
    vector<pair<int, int>> x(m);
    for (int i = 0; i < m; i++)
      cin >> x[i].fst;
    for (int i = 0; i < m; i++)
      cin >> x[i].snd;

    A.clear();
    sort(all(x));
    for (int i = 0, j = 0; i < m; i = j) {
      while (j < m and x[i].fst == x[j].fst) j++;
      A.push_back({x[i].fst, j-i});
    }

    n = sz(A);
    X.assign(n, 0);
    for (int i = 0; i < n; i++) {
      X[i] = (i ? X[i-1] : 0) + A[i].snd;
    }

    dp.assign(n, vector<int>(2, -1));
    cout << f(0, 0) << endl;
  }
}

