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

int n, c;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> c;

  int i = 1;
  int ans = min(c, n-1);
  while (i+c < n) {
    i += 1;
    ans += i;
  }

  cout << ans << endl;
}

