#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;

    set<ll> A;
    for (ll k = 1; k <= 10; k++) {
      A.insert((k*m) % 10);
    }

    ll s = 0;
    for (auto& x : A) {
      s += x;
    }

    ll x = n / m;
    ll ans = (x / sz(A)) * s;

    ll r = (x % sz(A));
    for (ll k = 1; k <= r; k++) {
      ans += (k*m) % 10;
    }

    cout << ans << endl;
  }
}

