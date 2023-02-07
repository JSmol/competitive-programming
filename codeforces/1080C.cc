#include <iostream>
#include <vector>
#include <algorithm>
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
ll t, x, y, x1, y1, x2, y2, x3, y3, x4, y4;

ll f(ll a, ll b, ll c, ll d) {
  if ((c - a) % 2 == 0 or (d - b) % 2 == 0)
    return (c - a) * (d - b) / 2;
  else
    return (c - a) * (d - b) / 2 + (a % 2 == b % 2);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> x >> y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    ll  x5 = max(x1, x3),
        y5 = max(y1, y3),
        x6 = min(x2, x4),
        y6 = min(y2, y4);

    ll ans = f(1, 1, x+1, y+1);

    ans += (x2 - x1 + 1) * (y2 - y1 + 1) - f(x1, y1, x2+1, y2+1);
    ans -= f(x3, y3, x4+1, y4+1);

    if (x5 > x6 or y5 > y6)
      "ay";
    else
      ans -= (x6 - x5 + 1) * (y6 - y5 + 1) - f(x5, y5, x6+1, y6+1);

    cout << ans << ' ' << x * y - ans << endl;
    
    
  }
}

