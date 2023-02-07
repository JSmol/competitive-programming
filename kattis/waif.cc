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

int N,M,S,T;
vector<vector<pair<int,int>>> G;

int n, m, p;

const int MAXNODE = 400;
const int INF = 1<<30;
int A[MAXNODE][MAXNODE];
vector<int> D;

bool levelgraph()
{
  queue<pair<int,int>> Q;
  D.assign(N,0);
  Q.push({S,1});
  while(!Q.empty()){
    int v = Q.front().fst, d = Q.front().snd; Q.pop();
    if(D[v]) continue;
    D[v]=d;
    for(int i = 0; i < N; ++i){
      if(A[v][i] > 0) Q.push({i,d+1});
    }
    
  }
  return D[T];
}

int path(int v, int w){
  if(v == T) return INF;
  for(int i = 0, x; i < N; ++i){
    if(A[v][i] and D[v] < D[i]) {
      x = min(A[v][i], w);
      if(int p = path(i, x)) {
        x = min(x,p); A[v][i] -= x; A[i][v] += x;
        return x;
      }
    }
    
  }
  return D[v] = 0;
}

int maxflow(){
  for(int i = 0; i < N; ++i) fill(A[i], A[i]+N, 0);
  for(int i = 0; i < N; ++i)
    for(auto& a : G[i])
      A[i][a.fst] += a.snd;
  int f = 0;
  while(levelgraph())
  {
    while(int p = path(S,INF)) f += p;
  }

  return f;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> p;
  N = n+m+p+2;
  M = 0;
  S = N-1;
  T = N-2;

  G.assign(N,{});
  for (int i = 0, k; i < n; i++) {
    cin >> k;
    for (int j = 0, x; j < k; j++) {
      cin >> x;
      G[i].push_back({n+x-1,1});
      M++;
    }
  }

  set<int> F;
  for (int i = 0, k; i < p; i++) {
    cin >> k;
    for (int j = 0, x; j < k; j++) {
      cin >> x;
      G[n+x-1].push_back({n+m+i,1});
      F.insert(x-1);
      M++;
    }
    int r;
    cin >> r;
    G[n+m+i].push_back({T,r});
    M++;
  }
  for(int i=0; i < m; ++i){
    if(F.count(i)) continue;
    G[n+i].push_back({T,1});
    M++;
  }

  for(int i = 0; i < n; ++i){
    G[S].push_back({i,1});
    M++;
  }
  
  debug(G);
  int f = maxflow();
  cout << f << endl;
}

