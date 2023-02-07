#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n, m;
vector<vector<int>> A;
vector<bool> V;
vector<int> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, {});
  V.assign(n, 0);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    A[u].push_back(v);
    A[v].push_back(u);
  }

  priority_queue<int, vector<int>, greater<int>> Q;
  Q.push(0);
  while (ans.size() < n) {
    int v = Q.top();
    Q.pop();

    if (V[v]) continue;
    V[v] = true;
    ans.push_back(v + 1);

    for (auto& a : A[v])
      Q.push(a);
  }
  cout << ans << endl;
}

