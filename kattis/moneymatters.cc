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
vector<vector<int>> A;
vector<int> D;
vector<bool> V;

int f(int v) {
  if (V[v]) return 0;
  V[v] = true;

  int s = D[v];
  for (auto& a : A[v]) {
    s += f(a);
  }

  return s;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  D.assign(n, 0);
  for (auto& o : D) cin >> o;

  A.assign(n, {});
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    A[u].push_back(v);
    A[v].push_back(u);
  }

  V.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (!V[i]) {
      int x = f(i);
      if (x < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }

  cout << "POSSIBLE" << endl;
}

