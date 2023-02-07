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
ll n, m;
vector<ll> A;

bool f(ll d) {
  ll i = 0, s = 0;
  while (i*d < n) {
    for (ll j = i*d; j < (i+1)*d and n-j-1 >= 0; j++) {
      s += A[n-j-1] - i;
      if (s >= m) return true;
    }

    i++;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  sort(begin(A), end(A));

  ll l = 1, h = n+1;
  while (h - l > 1) {
    ll mid = (h + l) / 2;
    if (f(mid))
      h = mid;
    else
      l = mid;
  }

  while (h > 0 and f(h)) h--;

  h++;
  if (f(h)) {
    cout << h << endl;
  } else {
    cout << -1 << endl;
  }
}

