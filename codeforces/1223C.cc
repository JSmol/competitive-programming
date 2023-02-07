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
    int n;
    cin >> n;
    vector<ll> A(n), X(n+1);
    for (auto& a : A) cin >> a;
    sort(all(A), greater<int>());
    for (int i = 1; i <= n; i++) X[i] = X[i-1] + A[i-1];
    ll x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    if (x < y) swap(a, b), swap(x, y);
    ll ans = -1;
    for (int i = 1, s = 0, t = 0, u = 0; i <= n; i++) {
      if (i % a == 0 and i % b == 0) u++;
      else if (i % a == 0) s++;
      else if (i % b == 0) t++;
      ll p = (X[u])/100 * (x+y);
      p += (X[u+s] - X[u])/100 * x;
      p += (X[u+s+t] - X[u+s])/100 * y;
      if (p >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}

