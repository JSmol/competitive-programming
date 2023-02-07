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

vector<char> c = { 'U', 'R', 'D', 'L', 'X' };
// 0 up / 1 right / 2 down / 3 left
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<vector<pair<int, int>>> A(n, vector<pair<int, int>>(n));
  for (auto& a : A) for (auto& x : a) cin >> x.fst >> x.snd, x.fst--, x.snd--;

  bool flag = 0;
  vector<vector<int>> S(n, vector<int>(n));
  vector<vector<char>> g(n, vector<char>(n, '#'));
  auto bfs = [&] (pair<int, int>& t) {
    if (A[t.fst][t.snd] != t) return 0;
    queue<pair<pair<int, int>, int>> Q;
    Q.push({t, 4});
    while (!Q.empty()) {
      auto [x, d] = Q.front(); Q.pop();
      if (S[x.fst][x.snd]) continue;
      S[x.fst][x.snd] = 1;
      g[x.fst][x.snd] = c[d];
      if (x.fst - 1 >= 0 and A[x.fst-1][x.snd] == t) Q.push({ { x.fst - 1, x.snd }, 2 });
      if (x.snd - 1 >= 0 and A[x.fst][x.snd-1] == t) Q.push({ { x.fst, x.snd - 1 }, 1 });
      if (x.fst + 1 <  n and A[x.fst+1][x.snd] == t) Q.push({ { x.fst + 1, x.snd }, 0 });
      if (x.snd + 1 <  n and A[x.fst][x.snd+1] == t) Q.push({ { x.fst, x.snd + 1 }, 3 });
    }

    return 1;
  };

  vector<vector<int>> V(n, vector<int>(n));
  function<int(int, int)> f = [&] (int i, int j) {
    if (V[i][j] or g[i][j] != '#') {
      return 1;
    } else {
      V[i][j] = 1;
      if (i - 1 >= 0 and A[i-1][j] == mp(-2, -2)) if (f(i - 1, j)) {
        g[i][j] = c[0];
        return 1;
      }
      if (j - 1 >= 0 and A[i][j-1] == mp(-2, -2)) if (f(i, j - 1)) {
        g[i][j] = c[3];
        return 1;
      }
      if (i + 1 <  n and A[i+1][j] == mp(-2, -2)) if (f(i + 1, j)) {
        g[i][j] = c[2];
        return 1;
      }
      if (j + 1 <  n and A[i][j+1] == mp(-2, -2)) if (f(i, j + 1)) {
        g[i][j] = c[1];
        return 1;
      }
      return 0;
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j].fst >= 0 and A[i][j].snd >= 0) {
        if (!bfs(A[i][j])) flag = 1;
      } else {
        if (!f(i, j)) flag = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == '#')
        flag = 1;
    }
  }

  if (flag) {
    cout << "INVALID" << endl;
  } else {
    cout << "VALID" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << g[i][j];
      cout << endl;
    }
  }
}

