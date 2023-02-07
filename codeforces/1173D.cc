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
int n;
const ll mod = 998244353;
vector<ll> X;
vector<bool> V;
vector<vector<int>> A;

ll f(int v) {
  V[v] = 1;
  ll s = X[sz(A[v])];
  for (auto& a : A[v]) {
    if (V[a]) continue;
    s *= f(a);
    s %= mod;
  }
  return s % mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  X.assign(n+1, 0);
  X[0] = 1;
  for (int i = 1; i < n; i++) {
    X[i] = (X[i-1] * i) % mod;
  }

  A.assign(n, {});
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--; v--;
    A[u].push_back(v);
    A[v].push_back(u);
  }

  V.assign(n, 0);
  cout << (n * f(0)) % mod << endl;
}

