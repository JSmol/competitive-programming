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

int n;
int dp[1<<16][64];

string p(int b) {
  string s = "";
  for (int i = 0; i < n; i++) s += ((b & (1 << i)) ? "1" : "0");
  return s;
}

int f(int b, int t) {
  int& x = dp[b][t];
  if (x != -1) return x;
  if (t == 0) return x = (b == (1 << n)-1);

  x = f(b, t-1);
  for (int i = 0; i < n; i++) {
    int flip = 0;
    for (int j = 0; j < t; j++) {
      if (i+j < n) flip |= (1 << (i+j));
    }

    x |= f(b ^ flip, t-1);
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  n = sz(s);

  int bm = 0;
  for (int i = 0; i < n; i++) {
    bm |= ((s[i] == '1') << i);
  }

  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j <= 2*n; j++)
      dp[i][j] = -1;

  for (int t = 0; t <= 2*n; t++) {
    if (f(bm, t)) {
      cout << t << endl;
      break;
    }
  }

  // for (int b = 0; b < (1 << n); b++) {
    // cout << "B = " << p(b) << ": ";
    // for (int t = 0; t <= 2*n; t++) {
      // cout << dp[b][t] << ' ';
    // }
    // cout << endl;
  // }
}
