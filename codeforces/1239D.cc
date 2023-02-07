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
  o << "["; int b = 0; for (auto a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

struct SCC {
  int n, c;
  vector<vector<int>> G, H;
  vector<int> ord, comp;
  vector<bool> V;
  SCC(int n) : n(n), G(n), H(n) { };
  void add_edge(int u, int v) {
    G[u].push_back(v);
    H[v].push_back(u);
  }
  void dfs1(int v) { 
    V[v] = true;
    for (auto& u : G[v])
      if (!V[u]) dfs1(u);
    ord.push_back(v);
  }
  void dfs2(int v) {
    comp[v] = c;
    for (auto& u : H[v])
      if (comp[u] == -1) dfs2(u);
  }
  vector<int> scc() {
    V.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (!V[i]) dfs1(i);
    comp.assign(n, -1); c = 0;
    for (int i = 0; i < n; i++) {
      int v = ord[n-1-i];
      if (comp[v] == -1) dfs2(v), c++;
    }
    return comp;
  }
  vector<vector<int>> dag() {
    set<pair<int, int>> S;
    vector<vector<int>> dag(c);
    for (int a = 0; a < n; a++) {
      for (auto& b : G[a]) {
        if (comp[a] == comp[b]) continue;
        if (!S.count({comp[a], comp[b]})) {
          dag[comp[a]].push_back(comp[b]);
          S.insert({comp[a], comp[b]});
        }
      }
    }
    return dag;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;   
    SCC G(2*n);
    for (int i = 0, a, b; i < m; i++) {
      cin >> a >> b; a--; b--; b += n;
      if (a == b-n) {
        G.add_edge(a, b);
        G.add_edge(b, a);
      } else {
        G.add_edge(b, a);
      }
    }

    if (n == 1) {
      cout << "No" << endl;
      continue;
    }

    auto comp = G.scc();
    auto dag = G.dag();
  
    int x = -1;
    for (int i = 0; i < sz(dag); i++) {
      if (dag[i].empty()) {
        x = i;
        break;
      }
    }
    
    assert(x != -1);
    vector<int> cats, people;
    for (int i = 0; i < 2*n; i++) {
      if (x == comp[i]) {
        cats.push_back(i);
      } else {
        people.push_back(i);
      }
    }

    if (!cats.empty() and !people.empty()) {
      cout << "Yes" << endl;
      cout << sz(people)/2 << ' ' << sz(cats)/2 << endl;
      for (auto& p : people) 
        if (p < n)
          cout << p+1 << ' ';
      cout << endl;
      for (auto& c : cats) 
        if (c >= n)
          cout << c-n+1 << ' ';
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

