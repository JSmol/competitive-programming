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

string s;

bool f(int i) {
  return i >= 0 and i < s.size();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  int i = 0;
  while (s[i] != '[') {
    i++;
    if (!f(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  s = s.substr(i);
  i = 1;
  while (s[i] != ':') {
    i++;
    if (!f(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  s = '[' + s.substr(i);
  reverse(begin(s), end(s));
  i = 0;
  while (s[i] != ']') {
    i++;
    if (!f(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  s = s.substr(i);
  i = 1;
  while (s[i] != ':') {
    i++;
    if (!f(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  s = ']' + s.substr(i);
  reverse(begin(s), end(s));
  int ans = s.size();
  if (ans == 3) {
    cout << -1 << endl;
    return 0;

  }
  for (int i = 2; i < s.size()-2; i++) {
    if (s[i] != '|') {
      ans--;
    }
  }

  cout << ans << endl;
}

