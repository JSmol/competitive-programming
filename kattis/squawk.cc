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

vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  g.assign(n, {});
  for(int i = 0; i < m; ++i){
      int a, b; cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
  }

  vector<vector<long long>> A(t+1, vector<long long>(n, 0));
  A[0][s] = 1;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < n; j++) {
      for (auto& a : g[j]) {
        A[i][a] += A[i-1][j];
      }
    }
  }

  long long ans = 0;
  for (auto a : A[t]) {
    ans += a;
  }

  cout << ans << endl;
}
