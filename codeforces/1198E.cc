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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  
  vector<int> X, Y;
  vector<pair<int, int>> xs(m), ys(m);
  for (int i = 0; i < m; i++) {
    cin >> xs[i].fst >> ys[i].fst >> xs[i].snd >> ys[i].snd;
    X.push_back(xs[i].fst);
    X.push_back(xs[i].snd+1);
    Y.push_back(ys[i].fst);
    Y.push_back(ys[i].snd+1);
  }

  sort(all(X));
  X.resize(unique(all(X)) - begin(X));
  sort(all(Y));
  Y.resize(unique(all(Y)) - begin(Y));

  int v = 2;
  vector<int> vx(sz(X)), vy(sz(Y));
  for (int i = 1; i < sz(X); i++) {
    cap[0][v] = X[i] - X[i-1];
    vx[i] = v;
    v++;
  }

  for (int i = 1; i < sz(Y); i++) {
    cap[v][1] = Y[i] - Y[i-1];
    vy[i] = v;
    v++;
  }

  for (int i = 1; i < sz(X); i++) {
    for (int j = 1; j < sz(Y); j++) {
      for (int k = 0; k < m; k++) {
        if (xs[k].fst <= X[i]-1 and X[i]-1 <= xs[k].snd and ys[k].fst <= Y[j]-1 and Y[j]-1 <= ys[k].snd)
          cap[vx[i]][vy[j]] = INF;
      }
    }
  }

  cout << maxflow(0, 1) << endl;
}

