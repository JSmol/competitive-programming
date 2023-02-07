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

typedef long long ll;
const int N = 202020;
ll n, q;
ll l[202020], r[202020], c[202020];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  vector<ll> A(n);
  for (auto& a : A) cin >> a;
  sort(all(A), greater<ll>());
  for (int i = 0, x, y; i < q; i++) cin >> x >> y, l[x]++, r[y+1]++;
  for (ll i = 0, s = 0; i < N; i++) s += l[i], s -= r[i], c[i] = s;
  sort(all(c), greater<ll>());
  ll i = 0, j = 0, ans = 0;
  while (j < n and i < N and c[i] > 0) {
    ans += c[i] * A[j], i++, j++;
  }

  cout << ans << endl;
}

