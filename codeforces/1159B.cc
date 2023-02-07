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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m = 1ll << 60;
  cin >> n;
  vector<ll> A(n);
  for (auto& a : A) cin >> a, m = min(m, a);

  if (n == 2) {
    cout << min(A[0], A[1]) << endl;
    return 0;
  }

  ll k = 1ll << 60, x = 1ll << 60;
  for (int i = 0; i <= n/2; i++) {
    ll y = n-i-1;
    x = min({x, A[i], A[n-i-1]});
    k = min(k, x/y);
  }
  cout << k << endl;
}

