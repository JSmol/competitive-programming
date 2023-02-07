#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    string s;
    cin >> n >> a >> b >> c >> s;

    int wins = 0;
    string ans(n, 'x');
    rep (i, 0, n) {
      if (s[i] == 'S' and a > 0) ans[i] = 'R', a--, wins++;
      if (s[i] == 'R' and b > 0) ans[i] = 'P', b--, wins++;
      if (s[i] == 'P' and c > 0) ans[i] = 'S', c--, wins++;
    }

    rep (i, 0, n) {
      if (ans[i] == 'x') {
        if (a > 0) {
          ans[i] = 'R'; a--;
          continue;
        }
        if (b > 0) {
          ans[i] = 'P'; b--;
          continue;
        }
        if (c > 0) {
          ans[i] = 'S'; c--;
          continue;
        }
        assert(0);
      }
    }

    if (wins >= (n+1)/2) {
      cout << "YES" << endl;
      cout << ans << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

