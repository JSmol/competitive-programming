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

int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int c = 0, d = 0, p = -1, ans = 0;
  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    if (max(c, d) <= min(a, b) and p != min(a, b)) {
      ans += min(a, b) - max(c, d) + (p != max(c, d));
      p = min(a, b);
    }

    c = a, d = b;
  }

  cout << ans << endl;
}

