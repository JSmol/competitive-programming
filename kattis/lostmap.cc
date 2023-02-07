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

struct union_find {
  int n; vector<int> A;
  union_find (int size) { n = size; A = vector<int>(n); iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

struct edge { int a, b, w; };

int n, m;
vector<edge> e;
vector<vector<edge>> G;

void kruskal () {
  sort(begin(e), end(e), [](const edge& a, const edge& b) { return a.w < b.w; });
  int i = 0;
  union_find uf{n+1};
  for (const auto& p : e) {
    if (i == n-1) break;
    if (uf.connected(p.a, p.b)) continue;

    uf.merge(p.a, p.b);
    G[p.a].push_back(p);
    //G[p.b].push_back(p);
    i++;  
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  G.assign(n+5, {}); 
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int w; cin >> w;
      if(j <= i) continue;
      edge ed; ed.a = i; ed.b = j; ed.w = w;
      e.push_back(ed);
    }
  }

  kruskal(); 
  for(int i = 1; i <= n; ++i){
    for(edge& ed : G[i]){
      cout << ed.a << " " << ed.b << endl;
    }
  
  }

}

