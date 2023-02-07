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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, q;
  cin >> n;
  vector<ll> A(n), D(n), S(n);
  for (auto& a : A) cin >> a;

  sort(all(A));
  for (int i = 1; i < n; i++) D[i] = max(0ll, A[i] - A[i-1] - 1);

  sort(all(D));
  for (int i = 1; i < n; i++) S[i] = S[i-1] + D[i];

  cin >> q;
  for (ll i = 0, l, r; i < q; i++) {
    cin >> l >> r;
    ll d = r - l;
    ll ub = upper_bound(all(D), d) - begin(D);

    ll x = (n - ub) * d;
    ll s = A[n-1] - A[0] + 1 + d, t = S[n-1];
    cout << s - (t - S[ub-1]) + x << ' ';
  }
  cout << endl;
}

