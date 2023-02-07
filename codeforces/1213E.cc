#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

int n;
string s, t;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s >> t;

  string ans = "";
  if (s[0] == t[1] and s[1] == t[0] and s[0] != s[1] and t[0] != t[1]) {
    char x;
    for (x = 'a'; ; x++) if (x != s[0] and x != s[1]) break;
    for (int i = 0; i < n; i++) ans += s[0];
    for (int i = 0; i < n; i++) ans += x;
    for (int i = 0; i < n; i++) ans += s[1];
  } else 
  if (s[0] == t[0] and s[1] != t[1] and s[1] != s[0] and t[1] != t[0]) {
    for (int i = 0; i < n; i++) ans += s[1];
    for (int i = 0; i < n; i++) ans += t[1];
    for (int i = 0; i < n; i++) ans += s[0];
  } else 
  if (s[1] == t[1] and s[0] != t[0] and s[1] != s[0] and t[1] != t[0]) {
    for (int i = 0; i < n; i++) ans += s[1];
    for (int i = 0; i < n; i++) ans += t[0];
    for (int i = 0; i < n; i++) ans += s[0];
  } else {
    string pat;
    for (char x = 'a'; x <= 'c'; x++) {
      for (char y = 'a'; y <= 'c'; y++) {
        for (char z = 'a'; z <= 'c'; z++) {
          if (x == y or y == z or z == x) continue;
          if((s[0] == x and s[1] == y)
          or (s[0] == y and s[1] == z)
          or (s[0] == z and s[1] == x)
          or (t[0] == x and t[1] == y)
          or (t[0] == y and t[1] == z)
          or (t[0] == z and t[1] == x)) continue;
          pat += x;
          pat += y;
          pat += z;
          goto next;
        }
      }
    }
next:
    assert(pat != "");
    for (int i = 0; i < n; i++) ans += pat;
  }

  cout << "YES" << endl;
  assert(sz(ans) == 3*n);
  cout << ans << endl;
}

