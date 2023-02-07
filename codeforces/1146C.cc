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

int t, n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    m = 128;
    int ans = 0, x = 0;
    while (m > 0) {
      int a = 0, b = 0;
      for (int i = 1; i <= n; i++)
        a += ((i/m) % 2 == 0),
        b += ((i/m) % 2 != 0);

      if (a == 0 or b == 0) {
        m /= 2; continue;
      }

      cout << a << ' ' << b;
      for (int i = 1; i <= n; i++) {
        if ((i/m) % 2 == 0)
          cout << ' ' << i;
      }

      for (int i = 1; i <= n; i++) {
        if ((i/m) % 2 != 0)
          cout << ' ' << i;
      }
      cout << endl;
      cin >> x;
      ans = max(ans, x);
      m /= 2;
    }

    cout << -1 << ' ' << ans << endl;
  }
}

