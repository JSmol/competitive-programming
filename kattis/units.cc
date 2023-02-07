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

typedef long long ll;

pair<ll, ll> times(pair<ll, ll> a, pair<ll, ll> b) {
  pair<ll, ll> ans = {(a.fst * b.fst), (a.snd * b.snd)};
  ll g = __gcd(ans.fst, ans.snd);
  ans.fst /= g;
  ans.snd /= g;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    map<string, int> M;
    map<int, string> N;
    for (int i = 0; i < n; i++) {
      string u;
      cin >> u;
      M.insert({u, i});
      N.insert({i, u});
    }
  
    // u = v * A[M[u]][M[v]]
    vector<vector<pair<ll, ll>>> A(n, vector<pair<ll, ll>>(n, {0,0}));
    for (int i = 0; i < n-1; i++) {
      string u, v, _;
      ll x;
      cin >> u >> _ >> x >> v;
      A[M[u]][M[v]] = {x, 1};
      A[M[v]][M[u]] = {1, x};
    }

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (A[i][k].fst and A[k][j].fst)
            A[i][j] = times(A[i][k], A[k][j]);

    // for (auto& a : A) debug(a);
    // cerr << endl;

    vector<pair<ll, string>> ans;
    for (int i = 0; i < n; i++) {
      int c = 0;
      for (auto a : A[i]) c += (a.fst == 1);
      if (c == 1) {
        for (int j = 0; j < n; j++) {
          ans.push_back({A[i][j].fst, N[j]});
        }
      }
    }

    sort(all(ans));
    for (int i = 0; i < n; i++) cout << ans[i].fst << ans[i].snd << (i != n-1 ? " = " : "\n");
  }
}

