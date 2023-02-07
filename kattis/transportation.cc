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

// maxflow O(n^2)
// nodes, edges, source, sink
int N, M, S, T;

// input graph adj list
vector<vector<pair<int, int>>> G;

const int MAXNODE = 5000;
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

//1 -> raw materials
//2 -> factory
//3 -> nothing
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int s, r, f, t;
  cin >> s >> r >> f >> t;
  
  N = MAXNODE;
  G.assign(N, {});
  S = 0;
  T = 1;

  map<string, int> m; 
  int num = 2;
  for(int i = 0; i < r; ++i) {
    string x; cin >> x;
    m[x] = num++;
    G[S].push_back({m[x], 1});
  }
  
  for(int i = 0; i < f; ++i) {
    string x; cin >> x;
    m[x] = num++;
    G[m[x]].push_back({T, 1});
  }

  for(int i = 0; i < t; ++i) {
    int a; cin >> a;
    int in = num++; int out = num++;
    G[in].push_back({out, 1});
    for(int j = 0; j < a; ++j){
      string x; cin >> x;
      if(!m.count(x)) m[x] = num++;
      G[m[x]].push_back({in, 1}); 
      G[out].push_back({m[x], 1});
    }
  }

  cout << maxflow() << endl;
}

