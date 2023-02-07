#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n;
vector<vector<int>> A;
vector<int> L, D;
vector<bool> V;

int dfs(int v) {
  if (V[v]) return 0;
  V[v] = true;

  if ((v != 1 and D[v] == 1) or (v == 1 and D[v] == 0)) return L[v] = 1;

  L[v] = 0;
  for (auto& a : A[v])
    L[v] += dfs(a);

  return L[v];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n+1, {});
  D.assign(n+1, 0);
  for (int i = 2, v; i <= n; i++) 
    cin >> v,
    D[i]++, D[v]++,
    A[i].push_back(v),
    A[v].push_back(i);

  V.assign(n+1, false);
  L.assign(n+1, 0);
  dfs(1);
  sort(begin(L), end(L));
  for (int i = 1; i < L.size(); i++) 
    cout << L[i] << ' ';
  cout << endl;
}

