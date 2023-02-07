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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = sz(s);

    if (n == 1) {
      if (s[0] == '?') s[0] = 'a';
      cout << s << endl;
      continue;
    }

    for (int i = 1; i+1 < n; i++) {
      if (s[i] == '?') {
        for (char x = 'a'; x <= 'c'; x++) {
          if (s[i-1] != x and s[i+1] != x) {
            s[i] = x;
            break;
          }
        }
      }

      if (s[i-1] == s[i] or s[i] == s[i+1]) {
        s = "-1";
        break;
      }
    }

    if (s == "-1") {
      cout << s << endl;
    } else {
      if (s[0] == '?') {
        for (char x = 'a'; x <= 'c'; x++) {
          if (s[1] != x) {
            s[0] = x;
            break;
          }
        }
      }
      if (s[n-1] == '?') {
        for (char x = 'a'; x <= 'c'; x++) {
          if (s[n-2] != x) {
            s[n-1] = x;
            break;
          }
        }
      }
      cout << s << endl;
    }
  }
}

