#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

int n, m, c;
vector<vector<int>> A;
vector<vector<bool>> X, V, ans;

int sqr(int x) {
  return x * x;
}

bool bounds(int i, int j) {
  return 0 <= i and i < n and 0 <= j and j < m;
}

bool f(int x) {
  ans.assign(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int li = i - x;
      int lj = j - x;
      int hi = i + x;
      int hj = j + x;
      if (bounds(li, lj) and bounds(hi, hj)) {
        int xs = A[hi][hj] - (li ? A[li-1][hj] : 0) - (lj ? A[hi][lj-1] : 0) + (li*lj ? A[li-1][lj-1] : 0);
        if (xs == sqr(1+2*x)) {
          ans[i][j] = 1;
        }
      }
    }
  }

  queue<tuple<int, int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j]) Q.push({i, j, 0});
    }
  }

  int v = 0;
  V.assign(n, vector<bool>(m, 0));
  while (!Q.empty()) {
    auto [i, j, s] = Q.front(); Q.pop();
    if (!bounds(i, j)) continue;
    if (!X[i][j]) continue;
    if (V[i][j]) continue;
    if (s > x) continue;
    V[i][j] = 1;
    v++;
    for (int x : {-1, 0, 1}) {
      for (int y : {-1, 0, 1}) {
        Q.push({i+x, j+y, s+1});
      }
    }
  }

  return v == c;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, vector<int>(m, 0));
  X.assign(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      c += x == 'X';
      X[i][j] = x == 'X';
      A[i][j] = X[i][j] + (i ? A[i-1][j] : 0) + (j ? A[i][j-1] : 0) - (i*j ? A[i-1][j-1] : 0);
    }
  }

  int l = 0, r = 1<<20;
  while (r - l > 1) {
    int m = (l+r) / 2;
    if (f(m)) l = m;
    else r = m;
  }

  while (!f(r)) r--;
  cout << r << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << (ans[i][j] ? 'X' : '.') << (j == m-1 ? "\n" : "");
  }
}

