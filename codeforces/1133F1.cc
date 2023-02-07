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

int n, m, b;
vector<vector<int>> A;
vector<int> D, V;
vector<pair<int, int>> E;

void f(int v) {
  queue<int> Q;
  Q.push(v);
  V[v] = true;
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
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, {});
  D.assign(n, 0);
  V.assign(n, 0);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--; v--;
    D[u]++; D[v]++;
    A[u].push_back(v);
    A[v].push_back(u);
    b = max({b, D[u], D[v]});
  }
  
  for (int i = 0; i < n; i++) {
    if (D[i] == b)
      f(i);
  }

  for (auto& e : E) cout << e.fst << ' ' << e.snd << endl;
}

