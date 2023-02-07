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

int n, m;
vector<string> g;
int v[55][55];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  g.assign(n, "");
  for (auto& r : g) cin >> r;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] or g[i][j] != 'L') continue;
      ans++;

      queue<pair<int, int>> Q;
      Q.push({i, j});
      while (!Q.empty()) {
        int x = Q.front().fst, y = Q.front().snd;
        Q.pop();

        if (v[x][y]) continue;
        v[x][y] = true;

        for (auto& k : {-1, 1}) {
          if (y+k >= 0 and y+k < m and !v[x][y+k] and g[x][y+k] != 'W')
            Q.push({x, y+k});

          if (x+k >= 0 and x+k < n and !v[x+k][y] and g[x+k][y] != 'W')
            Q.push({x+k, y});
        }
      }
    }
  }
  cout << ans << endl;
}

