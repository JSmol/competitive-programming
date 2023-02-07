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
  ll n, m, x = 0;
  cin >> n >> m;
  vector<ll> B(n), G(m);
  for (auto& b : B) cin >> b, x = max(x, b);
  for (auto& g : G) cin >> g;

  sort(all(B));
  sort(all(G));
  reverse(all(B));
  reverse(all(G));

  ll ans = 0;
  for (int i = 0; i < n; i++) ans += m * B[i];

  for (int i = 0, j = 0, k = 1; i < m; i++) {
    if (G[i] < x) {
      ans = -1;
      break;
    }

    if (G[i] > x) {
      ans += G[i] - B[j];
      k++;
      if (k == m) {
        k = 1;
        j++;
      }
    }

  }

  cout << ans << endl;
}

