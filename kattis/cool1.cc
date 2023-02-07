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
  int n; string s; cin >> n >> s;
  vector<string> A(n);
  for (auto& a : A) cin >> a;
  
  vector<vector<vector<int>>> V(sz(s), vector<vector<int>>(n, vector<int>(n, 0)));
  int j = -1, rr = -1, cc = -1;
  vector<pair<int, int>> ans;

  function<void(int, int, int)> f = [&] (int i, int r, int c) {
    i %= sz(s);

    if (V[i][r][c]) {
      j = i, rr = r, cc = c;
      return;
    }

    bool m = 0;
    V[i][r][c] = 1;
    if (s[i] == '<' and A[r][c-1] != '#') f(i+1, r, c-1), m = 1;
    if (s[i] == '<' and A[r][c-1] == '#') f(i+1, r, c);
    if (s[i] == '>' and A[r][c+1] != '#') f(i+1, r, c+1), m = 1;
    if (s[i] == '>' and A[r][c+1] == '#') f(i+1, r, c);
    if (s[i] == '^' and A[r-1][c] != '#') f(i+1, r-1, c), m = 1;
    if (s[i] == '^' and A[r-1][c] == '#') f(i+1, r, c);
    if (s[i] == 'v' and A[r+1][c] != '#') f(i+1, r+1, c), m = 1;
    if (s[i] == 'v' and A[r+1][c] == '#') f(i+1, r, c);

    if (j >= 0) {
      if (j == i and rr == r and cc == c) j = -1;
      if (m) ans.push_back({r, c});
    }
  };

  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
      if (A[r][c] == 'R') 
        A[r][c] = '.', f(0, r, c);

  int out = (sz(ans) == 0 ? 1 : sz(ans));
  for (int d = 1; d <= sz(ans); d++) {
    if (sz(ans) % d == 0) {
      bool p = 1;
      for (int i = 0; i < d; i++) {
        for (int j = i; j < sz(ans); j += d) {
          if (ans[i] != ans[j]) {
            p = 0;
          }
        }
      }
      if (p) {
        out = min(out, d);
      }
    }
  }

  cout << out << endl;
}

