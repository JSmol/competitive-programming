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

int n, m, x, y, z;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;
  for (auto& c : s) {
    if (c == '0') x++;
    if (c == '1') y++;
    if (c == '2') z++;
  }

  m = n/3;
  if (x < m) {
    for (auto& c : s) {
      if (c == '1' and y > m) 
        c = '0', x++, y--;
      if (c == '2' and z > m)
        c = '0', x++, z--;
      if (x == m) break;
    }
  }

  if (y < m and z > m) {
    for (auto& c : s) {
      if (c == '2' and z > m)
        c = '1', y++, z--;
      if (y == m) break;
    }
  }

  if (z < m) {
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == '1' and y > m) 
        s[i] = '2', z++, y--;
      if (s[i] == '0' and x > m)
        s[i] = '2', z++, x--;
      if (z == m) break;
    }
  }

  if (y < m and x > m) {
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == '0' and x > m)
        s[i] = '1', y++, x--;
      if (y == m) break;
    }
  }

  cout << s << endl;

}

