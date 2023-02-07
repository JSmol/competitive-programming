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
ll n, k, a, b, x, y;

ll d(ll s, ll t) {
  return abs(s-t) % (n*k);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k >> a >> b;

  x = n*k;
  ll s = a;
  for (ll l = b; l <= n*k; l += k) x = min(x, (n*k)/__gcd(d(s, l), n*k));
  for (ll l = k-b; l <= n*k; l += k) x = min(x, (n*k)/__gcd(d(s, l), n*k));
  for (ll l = b; l <= n*k; l += k) y = max(y, (n*k)/__gcd(d(s, l), n*k));
  for (ll l = k-b; l <= n*k; l += k) y = max(y, (n*k)/__gcd(d(s, l), n*k));
  s = k-a;
  for (ll l = b; l <= n*k; l += k) x = min(x, (n*k)/__gcd(d(s, l), n*k));
  for (ll l = k-b; l <= n*k; l += k) x = min(x, (n*k)/__gcd(d(s, l), n*k));
  for (ll l = b; l <= n*k; l += k) y = max(y, (n*k)/__gcd(d(s, l), n*k));
  for (ll l = k-b; l <= n*k; l += k) y = max(y, (n*k)/__gcd(d(s, l), n*k));

  cout << x << ' ' << y << endl;
}

