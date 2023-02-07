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

map<char, pair<int, int>> M = {
  { 'L', { -1,  0 } },
  { 'R', {  1,  0 } },
  { 'U', {  0,  1 } },
  { 'D', {  0, -1 } }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; string s; cin >> n >> s;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      x[i] = (i ? x[i-1] : 0) + M[s[i]].fst;
      y[i] = (i ? y[i-1] : 0) + M[s[i]].snd;
    }

    map<pair<int, int>, int> X;
    X[mp(0, 0)] = 0;
    
    int a = -1, b = -1, ans = 1 << 30;
    for (int i = 0; i < n; i++) {
      if (X.count(mp(x[i], y[i]))) {
        if (ans > i + 1 - X[mp(x[i], y[i])]) {
          ans = i + 1 - X[mp(x[i], y[i])];
          a = X[mp(x[i], y[i])] + 1;
          b = i + 1;
        }
      }
      X[mp(x[i], y[i])] = i+1;
    }

    if (ans < (1 << 30)) cout << a << ' ' << b << endl;
    else cout << -1 << endl;
  }
}

