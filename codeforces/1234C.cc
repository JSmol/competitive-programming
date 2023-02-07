#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

set<char> a = {'1', '2'};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;

    string s[2];
    cin >> s[0] >> s[1];

    string ans = "YES";
    int x = 0, i = 0, j = 0;
    while (j < n) {
      if (x == i) {
        if (a.count(s[i][j])) {
          x = i;
          j++;
        } else {
          x = i;
          i ^= 1;
        }
      } else {
        if (a.count(s[i][j])) {
          ans = "NO";
          break;
        } else {
          x = i;
          j++;
        }
      }
    }

    if (i != 1 or j != n) ans = "NO";

    cout << ans << endl;
  }
}

