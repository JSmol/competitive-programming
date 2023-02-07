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

const int inf = 1<<30;
int n;
vector<int> X, V, ans;
vector<vector<int>> A;

void f(int p) {
  V.assign(n, 0);
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    if (X[i] % 2 == p)
      Q.push({i, 0});
  }

  while (!Q.empty()) {
    auto [v, d] = Q.front(); Q.pop(); 
    if (X[v] % 2 != p) ans[v] = min(ans[v], d);
    if (V[v]) continue;
    V[v] = 1;
    for (auto& a : A[v]) {
      Q.push({a, d+1});
    }
  }
}

bool bounds(int x) {
  return 0 <= x and x < n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  X.assign(n, 0);
  A.assign(n, {});
  for (auto& a : X) cin >> a;

  for (int i = 0; i < n; i++) {
    if (bounds(i+X[i])) A[i+X[i]].push_back(i);
    if (bounds(i-X[i])) A[i-X[i]].push_back(i);
  }

  ans.assign(n, inf);
  f(0); f(1);
  for (int i = 0; i < n; i++) cout << (i ? " " : "") << (ans[i] == inf ? -1 : ans[i]);
  cout << endl;
}

