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

int n, m, k;
vector<pair<int, pair<int, int>>> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    A.push_back({w, {u, v}});
  }

  sort(all(A));
  set<int> K;
  for (int i = 0, x; i < k; i++) {
    cin >> x;
    K.insert(x);
  }

  for (auto& a : A) {
    if (K.count(a.snd.fst) and K.count(a.snd.snd))
      continue;
    if (!K.count(a.snd.fst) and !K.count(a.snd.snd))
      continue;
    cout << a.fst << endl;
    return 0;
  }
  
  cout << -1 << endl;
}

