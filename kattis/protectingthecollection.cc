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

int n, c, r;
int V[2020][2020][4][2];
vector<vector<char>> A;
int f(int x, int y, int d, int p) {
  if (x < 0 or y < 0) return 0;
  if (x == n) return y == r;
  if (y == n) return 0;

  if (V[x][y][d][p]) return 0;
  V[x][y][d][p] = 1;

  // x = cols, y = rows
  int ans = 0;
  if (!p and A[y][x] == '.') {
    if (d == 0) {
      ans |= f(x-1, y, 3, 1);
      ans |= f(x+1, y, 1, 1);
    }
    if (d == 1) {
      ans |= f(x, y-1, 0, 1);
      ans |= f(x, y+1, 2, 1);
    }
    if (d == 2) {
      ans |= f(x-1, y, 3, 1);
      ans |= f(x+1, y, 1, 1);
    }
    if (d == 3) {
      ans |= f(x, y+1, 2, 1);
      ans |= f(x, y-1, 0, 1);
    }
  }

  // 0123
  // NESW
  if (A[y][x] == '.') {
    if (d == 0) ans |= f(x, y-1, d, p);
    if (d == 1) ans |= f(x+1, y, d, p);
    if (d == 2) ans |= f(x, y+1, d, p);
    if (d == 3) ans |= f(x-1, y, d, p);
  }
  
  if (A[y][x] == '/') {
    if (d == 0) ans |= f(x+1, y, 1, p);
    if (d == 1) ans |= f(x, y-1, 0, p);
    if (d == 2) ans |= f(x-1, y, 3, p);
    if (d == 3) ans |= f(x, y+1, 2, p);
  }

  if (A[y][x] == '\\') {
    if (d == 0) ans |= f(x-1, y, 3, p);
    if (d == 1) ans |= f(x, y+1, 2, p);
    if (d == 2) ans |= f(x+1, y, 1, p);
    if (d == 3) ans |= f(x, y-1, 0, p);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> c >> r; r--; c--;
  A.assign(n, vector<char>(n, {}));
  for (auto& r : A) for (auto& e : r) cin >> e;
  cout << (f(c, 0, 2, 0) ? "YES" : "NO") << endl;
}

