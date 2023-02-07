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

int N, M, S, T;
vector<vector<pair<int, int>>> G;

const int MAXNODE = 4040;
const int INF = 1<<30;
int A[MAXNODE][MAXNODE];
vector<int> D;

bool levelgraph() {
  queue<pair<int, int>> Q;
  D.assign(N, 0);
  Q.push({S, 1});
  while (!Q.empty()) {
    int v = Q.front().fst, d = Q.front().snd; Q.pop();
    if (D[v]) continue;
    D[v] = d;
    for (int i = 0; i < N; i++)
      if (A[v][i] > 0)
        Q.push({i, d+1});
  }
  return D[T];
}

int path(int v, int w) {
  if (v == T) return INF;
  for (int i = 0, x; i < N; i++) {
    if (A[v][i] and D[v] < D[i]) {
      x = min(A[v][i], w);
      if (int p = path(i, x)) {
        x = min(x, p); A[v][i] -= x; A[i][v] += x;
        return x;
      }
    }
  }
  return D[v] = 0;
}

int maxflow() {
  for (int i = 0; i < N; i++) fill(A[i], A[i]+N, 0);
  for (int i = 0; i < N; i++)
    for (auto& a : G[i])
      A[i][a.fst] += a.snd;
  int f = 0;
  while (levelgraph())
    while (int p = path(S, INF))
      f += p;

  return f;
}

char C[45][45];
int in[45][45];
int out[45][45];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h; cin >> w >> h;
  int n = 2;
  S = 0;
  T = 1;
  G.assign(MAXNODE, {});

  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cin >> C[i][j];
      if (C[i][j] != 'A' and C[i][j] != 'B') {
        if (C[i][j] == '0') continue;
        G[n].push_back({n+1, C[i][j] - '0'});
        in[i][j] = n;
        out[i][j] = n+1;
        n += 2;
      } else {
        if (C[i][j] == 'A') {
          G[S].push_back({n, INF});
          in[i][j] = n;
          out[i][j] = n;
          n++;
        } else {
          G[n].push_back({T, INF});
          in[i][j] = n;
          out[i][j] = n;
          n++;
        }
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (C[i][j] == '0') continue;
      for (auto d : {-1, 1}) {
        if (C[i][j] != 'A' and C[i][j] != 'B') {
          if (0 <= i + d and i + d < h and C[i+d][j] != 'A' and C[i+d][j] != '0') {
            G[out[i][j]].push_back({in[i+d][j], INF});
          }
          if (0 <= j + d and j + d < w and C[i][j+d] != 'A' and C[i][j+d] != '0') {
            G[out[i][j]].push_back({in[i][j+d], INF});
          }
        }

        if (C[i][j] == 'A') {
          if (0 <= i + d and i + d < h and C[i+d][j] != 'A' and C[i+d][j] != '0') {
            G[out[i][j]].push_back({in[i+d][j], INF});
          }
          if (0 <= j + d and j + d < w and C[i][j+d] != 'A' and C[i][j+d] != '0') {
            G[out[i][j]].push_back({in[i][j+d], INF});
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cerr << i << ' '; debug(G[i]);
  }

  N = n;
  cout << maxflow() << endl;
}

