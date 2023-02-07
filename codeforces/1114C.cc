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
ll n, b;

ll g(ll d) {
  ll ans = 0, m = n;
  while (m >= d) {
    ans += m / d;
    m /= d;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> b;

  vector<pair<ll, ll>> f;
  ll k = 2, l = b;
  while (l > 1 and k*k <= l) {
    while (l % k == 0) {
      if (f.empty() or f.back().fst != k)
        f.push_back({k, 1});
      else
        f.back().snd++;
      l /= k;
    }
    k++;
  }

  if (l != 1) f.push_back({l, 1}), l = 1;

  ll ans = 1ll << 60;
  for (auto& a : f) {
    ans = min(ans, g(a.fst) / a.snd);
  }

  cout << ans << endl;
}

