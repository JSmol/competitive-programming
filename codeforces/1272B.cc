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
    int r = 0, l = 0, u = 0, d = 0;
    for (auto& x : s) {
      r += x == 'R';
      l += x == 'L';
      u += x == 'U';
      d += x == 'D';
    }
    
    string ans;
    if (min(l, r) == 0 and min(u, d) > 0) u = d = 1;
    if (min(u, d) == 0 and min(l, r) > 0) l = r = 1;
    for (int i = 0; i < min(l, r); i++) ans += 'R';
    for (int i = 0; i < min(u, d); i++) ans += 'U';
    for (int i = 0; i < min(l, r); i++) ans += 'L';
    for (int i = 0; i < min(u, d); i++) ans += 'D';

    cout << sz(ans) << endl;
    cout << ans << endl;
  }
}

