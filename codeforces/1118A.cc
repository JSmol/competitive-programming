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
ll a, b, c, n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> c;
  while (c--) {
    cin >> n >> a >> b;
    ll ans = 0;
    if (b / 2 < a) {
      ans += b * (n / 2);
      ans += a * (n % 2);
    } else {
      ans += a * n;
    }

    cout << ans << endl;
  }
}

