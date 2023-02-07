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

int dijkstra(vector<vector<pair<int, int>>> A, int n, int s, int t) {
  vector<int> D(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
  PQ.push({0, s});
  while (!PQ.empty()) {
    int v = PQ.top().snd; int d = PQ.top().fst;
    PQ.pop();

    if (D[v] != -1) continue;
    D[v] = d;

    for (auto& a : A[v]) {
      int u = a.fst; int w = a.snd;
      PQ.push({d + w, u});
    }
  }

  return D[t];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q, s;
  while (cin >> n >> m >> q >> s and n != 0) {
    vector<vector<pair<int, int>>> A(n, vector<pair<int, int>>());
    for (int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w;
      A[u].push_back({v, w});
    }

    while (q--) {
      int t;
      cin >> t;
      int ans = dijkstra(A, n, s, t);
      if (ans != -1) cout << ans << endl;
      else cout << "Impossible" << endl;
    }
    cout << endl;
 }
}

