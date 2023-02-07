#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

typedef long long ll;
ll n, k, a, b;
vector<ll> A;

ll g(ll l, ll r) {
  ll i = lower_bound(begin(A), end(A), l) - begin(A);
  ll j = upper_bound(begin(A), end(A), r) - begin(A);
  
  return j - i;
}

ll f(ll l, ll r) {
  if ((r - l) < 2) {
    ll m = g(l+1, r);
    if (m > 0) {
      return b * m;
    } else {
      return a;
    }
  }

  ll x, m = g(l+1, r);
  if (m > 0) {
    x = min(b * m * (r - l), f(l, (r + l) / 2) + f((r + l) / 2, r));
  } else {
    x = a;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k >> a >> b;
  A.assign(k, 0);
  for (auto& e : A) cin >> e;

  sort(begin(A), end(A));

  cout << f(0, 1 << n) << endl;

}

