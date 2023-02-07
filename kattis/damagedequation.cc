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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c, d; cin >> a >> b >> c >> d;

  int p = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {

      if (i == 0 and j == 0) {
        if (a * b == c * d) {
          cout << a << " * " << b << " = " << c << " * " << d << endl;
          p = 1;
        }
      }

      if (i == 0 and j == 1) {
        if (a * b == c + d) {
          cout << a << " * " << b << " = " << c << " + " << d << endl;
          p = 1;
        }
      }

      if (i == 0 and j == 2) {
        if (a * b == c - d) {
          cout << a << " * " << b << " = " << c << " - " << d << endl;
          p = 1;
        }
      }

      if (i == 0 and j == 3) {
        if (d == 0) continue;
        if (a * b == c / d) {
          cout << a << " * " << b << " = " << c << " / " << d << endl;
          p = 1;
        }
      }

      if (i == 1 and j == 0) {
        if (a + b == c * d) {
          cout << a << " + " << b << " = " << c << " * " << d << endl;
          p = 1;
        }
      }

      if (i == 1 and j == 1) {
        if (a + b == c + d) {
          cout << a << " + " << b << " = " << c << " + " << d << endl;
          p = 1;
        }
      }

      if (i == 1 and j == 2) {
        if (a + b == c - d) {
          cout << a << " + " << b << " = " << c << " - " << d << endl;
          p = 1;
        }
      }

      if (i == 1 and j == 3) {
        if (d == 0) continue;
        if (a + b == c / d) {
          cout << a << " + " << b << " = " << c << " / " << d << endl;
          p = 1;
        }
      }

      if (i == 2 and j == 0) {
        if (a - b == c * d) {
          cout << a << " - " << b << " = " << c << " * " << d << endl;
          p = 1;
        }
      }

      if (i == 2 and j == 1) {
        if (a - b == c + d) {
          cout << a << " - " << b << " = " << c << " + " << d << endl;
          p = 1;
        }
      }

      if (i == 2 and j == 2) {
        if (a - b == c - d) {
          cout << a << " - " << b << " = " << c << " - " << d << endl;
          p = 1;
        }
      }

      if (i == 2 and j == 3) {
        if (d == 0) continue;
        if (a - b == c / d) {
          cout << a << " - " << b << " = " << c << " / " << d << endl;
          p = 1;
        }
      }

      if (i == 3 and j == 0) {
        if (b == 0) continue;
        if (a / b == c * d) {
          cout << a << " / " << b << " = " << c << " * " << d << endl;
          p = 1;
        }
      }

      if (i == 3 and j == 1) {
        if (b == 0) continue;
        if (a / b == c + d) {
          cout << a << " / " << b << " = " << c << " + " << d << endl;
          p = 1;
        }
      }

      if (i == 3 and j == 2) {
        if (b == 0) continue;
        if (a / b == c - d) {
          cout << a << " / " << b << " = " << c << " - " << d << endl;
          p = 1;
        }
      }

      if (i == 3 and j == 3) {
        if (b == 0) continue;
        if (d == 0) continue;
        if (a / b == c / d) {
          cout << a << " / " << b << " = " << c << " / " << d << endl;
          p = 1;
        }
      }

    }
  }

  if (!p) cout << "problems ahead" << endl;
}

