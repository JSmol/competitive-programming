#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

/*
 *  70 71 72 73 .... 77
 *  
 *  .
 *  .
 *  .
 *  
 *  20 21 22 23 .... 27
 *  10 11 12 13 .... 17
 *  00 01 02 03 .... 07
 */

int V[8][8][4];
vector<pair<int, int>> ans;
int t, a, b, c, d;
int f(int x, int y, int m) {
  if (x == c and y == d) return 1;
  if (m == 4) return 0;

  if (V[x][y][m]) return 0;
  V[x][y][m] = 1;

  rep (i, 0, 8) {
    rep (j, 0, 8) {
      if (i == x and j == y) continue;
      if (i+j == x+y or i-j == x-y) {
        if (f(i, j, m+1)) {
          ans.push_back({i, j});
          return 1; 
        }
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    char x, y;
    cin >> x >> b >> y >> d;
    a = x - 'A'; b--;
    c = y - 'A'; d--;
    rep (i,0,8) rep (j,0,8) rep (k,0,4) V[i][j][k] = 0;
    ans.clear();
    if (f(a, b, 0)) {
      cout << sz(ans);
      ans.push_back({a, b});
      reverse(all(ans));
      trav (a, ans) cout << ' ' << (char) (a.fst + 'A') << ' ' << a.snd + 1;
      cout << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
}

