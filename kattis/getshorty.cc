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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long double ld;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  while (cin >> n >> m and n != 0) {
    vector<vector<pair<int, ld>>> A(n);
    for (int i = 0; i < m; i++) {
      int u, v; ld w;
      cin >> u >> v >> w;
      A[u].push_back({v, w});
      A[v].push_back({u, w});
    }
  
    vector<bool> V(n, 0);
    priority_queue<pair<ld, int>> PQ;
    PQ.push({1, 0});
    while (!PQ.empty()) {
      int v = PQ.top().snd; ld w = PQ.top().fst;
      PQ.pop();

      if (V[v]) continue;
      V[v] = 1;

      if (v == n-1) {
        cout << fixed << setprecision(4) << w << endl;
        break;
      }

      for (auto& a : A[v]) {
        PQ.push({w * a.snd, a.fst});
      }
    }
  }
}

