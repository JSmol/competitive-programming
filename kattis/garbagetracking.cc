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

typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int r, q; cin >> r >> q;
  
  const int off = 2500;
  const int n = 5000;
  vector<vector<ll>> X(n, vector<ll>(n, 0));
  vector<vector<ll>> Y(n, vector<ll>(n, 0));
  for (int i = 0; i < r; i++) {
    int x, y, w, h, c; cin >> x >> y >> w >> h >> c;
    x += off; y += off;
    X[x][y] += c;
    X[x+w][y] -= c;
    X[x][y+h] += c;
    X[x+w][y+h] -= c;
    Y[x][y] += c;
    Y[x][y+h] -= c;
    Y[x+w][y] += c;
    Y[x+w][y+h] -= c;
  }

  vector<vector<ll>> XX(n, vector<ll>(n, 0));
  vector<vector<ll>> YY(n, vector<ll>(n, 0));
  for (int j = 1; j < n; j++) {
    ll s = 0;
    for (int i = 1; i < n; i++) {
      s += X[i][j];
      XX[i][j] = s;
    }
  }
  for (int i = 1; i < n; i++) {
    ll s = 0;
    for (int j = 1; j < n; j++) {
      s += Y[i][j];
      YY[i][j] = s;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      XX[i][j] += XX[i-1][j] + XX[i][j-1] - XX[i-1][j-1];
      YY[i][j] += YY[i-1][j] + YY[i][j-1] - YY[i-1][j-1];
    }
  }

  auto sum = [&] (int x1, int y1, int x2, int y2) {
    return XX[x2-1][y2] + XX[x1-1][y1-1] - XX[x2-1][y1-1] - XX[x1-1][y2]
         + YY[x2][y2-1] + YY[x1-1][y1-1] - YY[x1-1][y2-1] - YY[x2][y1-1];
  };

  vector<ll> ans;
  for (int i = 0; i < q; i++) {
    int x, y, w, h; cin >> x >> y >> w >> h;
    x += off; y += off;
    ans.push_back(sum(x, y, x+w, y+h));
  }
  
  for (int i = 0; i < q; i++)
    cout << ans[i] << endl;
}

