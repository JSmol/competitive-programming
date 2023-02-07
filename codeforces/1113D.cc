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

bool h(string& s, int n) {
  char t = s[0], p = t;
  for (auto& c : s) {
    if (p == c and c != t)
      return true;

    p = c;
  }
  return false;
}

int g(string& s, int n) { 
  string t = s;
  reverse(begin(t), end(t));
  if (s == t) {
    return true;
  } else {
    return false;
  }
}

int f(string& s) {
  int x = 0;
  for (auto& c : s)
    if (c == s[0]) x++;
  return x;
}

string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  int n = s.length();

  if (f(s) == n) {
    cout << "Impossible" << endl;
    return 0;
  }

  if (n % 2 == 0) {
    string l = s.substr(0, n/2);
    string r = s.substr(n/2, n);

    if (g(l, n/2) and n % 4 == 0 and h(l, n/2)) {
      cout << 1 << endl;
      return 0;
    }

    if (g(l, n/2) and n % 4 == 0 and !h(l, n/2)) {
      cout << 2 << endl;
      return 0;
    }

    if (g(l, n/2) and n % 4 != 0) {
      cout << 2 << endl;
      return 0;
    } else {
      cout << 1 << endl;
      return 0;
    }
  } else {
    string l = s.substr(0, n/2);
    string r = s.substr(n/2 + 1, n);

    if (f(l) == n/2) {
      cout << "Impossible" << endl;
      return 0;
    } 

    cout << 2 << endl;
    return 0;
  }
}

