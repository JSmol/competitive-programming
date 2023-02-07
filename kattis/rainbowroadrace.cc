#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

string colors = "ROYGBIV";
const int p = 2 << 7;
int n, m;
vector<vector<tuple<int, int, int>>> G;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  G.assign(n+1, {});
  for (int i = 0; i < m; i++) {
    int u, v, w, c;
    char col;
    cin >> u >> v >> w >> col;
    c = (1 << colors.find(col));
    G[u].push_back({v, w, c});
    G[v].push_back({u, w, c});
  }
  
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;
  PQ.push({0, 1, 0});
  set<pair<int, int>> D;
  while (!PQ.empty()) {
    int d = get(PQ.top(), 0), v = get(PQ.top(), 1), c = get(PQ.top(), 2);
    PQ.pop();

    if (D.count({v, c})) continue;
    if (v == 1 and c == (1 << 7) - 1) {
      cout << d << endl;
      break;
    }

    D.insert({v, c});
    for (auto& a : G[v])
      PQ.push({d + get(a, 1), get(a, 0), c | get(a, 2)});

  }

}

