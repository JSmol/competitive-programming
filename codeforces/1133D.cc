#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

typedef long long ll;
ll n;
map<pair<ll, ll>, ll> M;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<ll> A(n), B(n);
  for (auto& x : A) cin >> x;
  for (auto& x : B) cin >> x;

  int o = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] == 0 and B[i] == 0) o++;
    else if (A[i] == 0) continue;
    else if (B[i] == 0) M[{1, 0}]++;
    else {
      ll d = __gcd(A[i], B[i]);
      M[{A[i]/d, B[i]/d}]++;
    }
  }

  ll ans = 0;
  for (auto& e : M) ans = max(ans, e.snd);
  cout << ans + o << endl;
}

