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
ll n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  vector<ll> A(n), D(n), P(m);
  for (int i = 0; i < n; i++) cin >> A[i], D[i] = (i ? A[i] - A[i-1] : 0);
  for (auto& p : P) cin >> p;

  ll g = D[1];
  for (int i = 1; i < n; i++) g = __gcd(g, D[i]);
  assert(g > 0);
  for (int i = 0; i < m; i++) {
    if (P[i] != 0 and g % P[i] == 0) {
      cout << "YES" << endl;
      cout << A[0] << ' ' << i+1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}

