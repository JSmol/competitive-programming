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

typedef long long ll;
const ll mod = 1000000007;
ll n, k;
vector<vector<pair<ll, ll>>> A;
vector<bool> V;

ll f(int v) {
  if (V[v]) return 0;

  ll x = 0;
  for (auto& a : A[v]) {

  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, {});
  for (int i = 0, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    A[u].push_back({v, w});
    A[v].push_back({u, w});
  }

  V.assign(n, 0);
  cout << f(0) << endl;
}

