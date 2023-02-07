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
ll h, n, m;
vector<ll> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> h >> n;
  A.assign(n, 0);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i], s -= A[i];
    m = max(m, s);
    if (s >= h) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  if (s <= 0) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = ((h-m) / s) * n;
  h -= ((h-m) / s) * s;

  for (int i = 0; i < 2*n; i++) {
    h+=A[i%n];
    if (h <= 0) {
      cout << ans + i + 1 << endl;
      return 0;
    }
  }
}

