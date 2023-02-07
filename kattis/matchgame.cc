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

vector<vector<int>> X = {
  {1,1,1,0,1,1,1},
  {0,0,1,0,0,1,0},
  {1,0,1,1,1,0,1},
  {1,0,1,1,0,1,1},
  {0,1,1,1,0,1,0},
  {1,1,0,1,0,1,1},
  {1,1,0,1,1,1,1},
  {1,0,1,0,0,1,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

int g(int a) {
  return accumulate(all(X[a]), 0);
}

vector<int> f(int a, int b) {
  vector<int> r(7);
  for (int i = 0; i < 7; i++) {
    r[i] = X[a][i] ^ X[b][i];
  }

  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = sz(s), s1 = 0, s2 = 0;
  vector<vector<int>> A(n);
  for (int i = 0; i < n; i++) {
    A[i] = f(s[i]-'0', t[i]-'0');
    s1 += g(s[i]-'0');
    s2 += g(t[i]-'0');
  }

  int x = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 7; j++)
      x += A[i][j];

  if (s1 == s2 and x == 2) cout << "yes" << endl;
  else cout << "no" << endl;
}

