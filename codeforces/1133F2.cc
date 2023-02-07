#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

int n, m, d;
vector<vector<int>> A;
vector<int> V, D;
vector<pair<int, int>> E;

void f(int v) {
  V[v] = true;
  for (auto& a : A[v]) {
    if (!V[a])
      f(a);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> d;
  A.assign(n, {});
  V.assign(n, 0);
  D.assign(n, 0);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--; v--;
    A[u].push_back(v);
    A[v].push_back(u);
  }

  if (A[0].size() < d) {  
    cout << "NO" << endl;
    return 0;
  }
  
  set<int> s;
  V[0] = true;
  for (auto& a : A[0]) {
    if (!V[a])
      s.insert(a),
      f(a);
  }

  if (s.size() > d) {
    cout << "NO" << endl;
    return 0;
  }

  V.assign(n, 0);
  queue<int> Q;
  V[0] = 1;
  for (auto& e : s) {
    d--;
    E.push_back({1, e+1});
    Q.push(e);
    V[e] = true;
  }

  for (auto& a : A[0]) {
    if (d > 0 and !V[a]) {
      d--;
      E.push_back({1, a+1});
      Q.push(a);
      V[a] = true;
    }
  }

  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();

    for (auto& a : A[x]) {
      if (!V[a])
        E.push_back({x+1, a+1}),
        V[a] = true,
        Q.push(a);
    }
  }

  cout << "YES" << endl;
  for (auto& e : E) cout << e.fst << ' ' << e.snd << endl;
}

