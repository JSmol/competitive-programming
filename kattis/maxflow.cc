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

const int INF = 1<<30;
const int N = 2002;
int cap[N][N];
vector<int> D;

bool levelgraph(int s, int t) {
  queue<pair<int, int>> Q;
  D.assign(N, 0);
  Q.push({s, 1});
  while (!Q.empty()) {
    auto [v, d] = Q.front(); Q.pop();
    if (D[v]) continue;
    D[v] = d;
    for (int i = 0; i < N; i++)
      if (cap[v][i] > 0)
        Q.push({i, d+1});
  }
  return D[t];
}

int path(int v, int w, int t) {
  if (v == t) return INF;
  for (int i = 0, x; i < N; i++) {
    if (cap[v][i] and D[v] < D[i]) {
      x = min(cap[v][i], w);
      if (int p = path(i, x, t)) {
        x = min(x, p); cap[v][i] -= x; cap[i][v] += x;
        return x;
      }
    }
  }
  return D[v] = 0;
}

int maxflow(int s, int t) {
  int f = 0;
  while (levelgraph(s, t))
    while (int p = path(s, INF, t))
      f += p;

  return f;
}

int A[N][N];
int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    cap[u][v] += w;
    A[u][v] += w;
  }

  int f = maxflow(s, t);
  int u[5*N], v[5*N], c[5*N], k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // if the capacity has changed
      if (A[i][j] > cap[i][j])
        u[k] = i, v[k] = j, c[k] = A[i][j] - cap[i][j], k++;
    }
  }

  cout << n << ' ' << f << ' ' << k << endl;
  for (int i = 0; i < k; i++) {
    // edge u[i] -> v[i] has flow c[i] in solution.
    cout << u[i] << ' ' << v[i] << ' ' << c[i] << endl;
  }
}
