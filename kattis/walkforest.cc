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

vector<vector<pair<int, int>>> A;
vector<int> D;
int dp[1010];

int f(int v) {
  if (v == 1) return 1;
  if (dp[v] != -1) return dp[v];

  int& ans = dp[v];
  ans = 0;
  for (auto& a : A[v])
    if (D[a.fst] < D[v])
      ans += f(a.fst);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  while (cin >> n >> m and n != 0) {
    A.assign(n, {});
    for (int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w; u--; v--;
      A[u].push_back({v, w});
      A[v].push_back({u, w});
    }

    D.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, 1});
    while (!PQ.empty()) {
      int d = PQ.top().fst; int v = PQ.top().snd;
      PQ.pop();

      if (D[v] != -1) continue;
      D[v] = d;

      for (auto& a : A[v]) {
        PQ.push({d + a.snd, a.fst});
      }
    }
  
    fill(dp, dp+n, -1);
    cout << f(0) << endl;
  }
}

