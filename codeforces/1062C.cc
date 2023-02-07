#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

typedef long long ll;
ll mod = 1000000007;
ll n, q;
string s;
vector<ll> A, B, C;

ll fexp(ll m, ll p) {
  ll r = 1;
  ll x = m;

  while (p > 0) {
    if (p & 1)
      p -= 1,
      r = (r * x) % mod;
    else
      p >>= 1,
      x = (x * x) % mod;
  }

  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q >> s;
  A.assign(n+1, 0);
  B.assign(n+1, 0);
  C.assign(q, 0);
  for (int i = 0; i < n; i++)
    A[i+1] = A[i] + (s[i] == '1'),
    B[i+1] = B[i] + (s[i] == '0');

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    ll m = A[r] - A[l-1];
    ll k = B[r] - B[l-1];

    ll ans = (fexp(2, m) - 1) % mod;
    ans += (ans * (fexp(2, k) - 1)) % mod;

    C[i] = ans % mod;
  }

  for (auto& ans : C) cout << ans << '\n';
}

