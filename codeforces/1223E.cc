#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

typedef long long ll;
ll n, k;
vector<vector<pair<ll, ll>>> A;
vector<vector<ll>> V;
ll f(ll v, ll p, int q) {
  if (v != 0 and sz(A[v]) == 1) return 0;
  if (V[v][p]) return V[v][p];
  ll s = 0;
  vector<pair<ll, ll>> X(sz(A[v]));
  for (int i = 0; i < sz(A[v]); i++) {
    if (A[v][i].fst == q) continue;
    X[i].fst = f(A[v][i].fst, 0, v);
    X[i].snd = f(A[v][i].fst, 1, v) + A[v][i].snd;
    s += X[i].fst;
  }

  ll t = 0;
  ll ans = s;
  sort(all(X), [] (auto& a, auto& b) { return a.snd - a.fst > b.snd - b.fst; });
  for (int i = 1; i <= min(sz(A[v]), int(k-p)); i++) {
    s -= X[i-1].fst;
    t += X[i-1].snd;
    ans = max(ans, s + t);
  }

  return V[v][p] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    A.assign(n, {});
    for (ll i = 0, u, v, w; i < n-1; i++) {
      cin >> u >> v >> w; u--; v--;
      A[u].push_back({v, w});
      A[v].push_back({u, w});
    }
    
    V.assign(n, {0, 0});
    ll ans = f(0, 0, -1);
    cout << ans << endl;
  }
}

