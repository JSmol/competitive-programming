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

/*  Finds length of longest palidrome starting at each position in O(n)
 *  manacher("abacaba", 1) => {0, 1, 0, 3, 0, 1, 0}
 *  manacher("aabbaa",  0) => {1, 0, 3, 0, 1}
 */

vector<int> manacher(string s, bool parity) {
  int n = s.size(), z = parity, l = 0, r = 0;
  vector<int> ret(n - !z, 0);
  for (int i = 0; i < n - !z; ++i) {
    if (i + !z < r) ret[i] = min(r - i, ret[l + r - i - !z]);
    int L = i - ret[i] + !z, R = i + ret[i];
    while (L - 1 >= 0 and R + 1 < n and s[L - 1] == s[R + 1])
      ++ret[i], --L, ++R;
    if (R > r) l = L, r = R;
  }
  
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = sz(s);

    string t; int m = 0;
    for (int i = 0; i < n/2; i++) {
      if (s[i] == s[n-i-1]) {
      } else {
        m = i;
        for (int j = i; j <= n-i-1; j++)
          t += s[j];
        break;
      }
    }

    if (t == "") {
      cout << s << endl;
      continue;
    }

    auto X = manacher(t, 0);
    auto Y = manacher(t, 1);
    n = sz(t);

    int best = 0, ans = 0, p = 0;
    for (int i = 0; i < n; i++) {
      if (i < n-1 and i - X[i] + 1 == 0 and best < 2*X[i]) {
        best = 2*X[i];
        ans = 0;
        p = 0;
      }

      if (i < n-1 and i + X[i] == n-1 and best < 2*X[i]) {
        best = 2*X[i];
        ans = n-best;
        p = 0;
      }

      if (i - Y[i] == 0 and best < 2*Y[i] + 1) {
        best = 2*Y[i] + 1;
        ans = 0;
        p = 1;
      }

      if (i + Y[i] == n-1 and best < 2*Y[i] + 1) {
        best = 2*Y[i] + 1;
        ans = n-best;
        p = 1;
      }
    }
  
    if (p) {
      string x = s.substr(0, m) + t.substr(ans, best) + s.substr(sz(s)-m, m);
      cout << x << endl;
    } else {
      string x = s.substr(0, m) + t.substr(ans, best) + s.substr(sz(s)-m, m);
      cout << x << endl;
    }
  }
}

