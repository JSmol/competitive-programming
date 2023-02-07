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
  int n, d, w; cin >> n >> d >> w; cin.ignore();
  vector<string> A(n);
  for (int i = 0; i < n; i++) {
    getline(cin, A[i]);
  }

  debug(A);

  vector<string> X;
  string s;
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      for (int j = sz(A[i])-1; j >= 0; j--) {
        if (A[i][j] == ' ') break;
        if (A[i][j] == '.') X.push_back(s), s = "";
        else s += A[i][j];
      }
    } else {
      for (int j = 0; j < sz(A[i]); j++) {
        if (A[i][j] == ' ') break;
        if (A[i][j] == '.') X.push_back(s), s = "";
        else s += A[i][j];
      }
    }
  }

  X.push_back(s);

  s = "";
  int m = 1;
  for (int i = 0; i < sz(X); i++) {
    if (s == "") {
      if (sz(s) + sz(X[i]) <= w) s += X[i];
      else assert(0);
    } else {
      if (sz(s) + sz(X[i]) + 1 <= w) s += '.' + X[i];
      else s = X[i], m++;
    }
  }

  cout << m << endl;
}

