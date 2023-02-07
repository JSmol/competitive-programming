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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  int t = 0, b = 0;
  for (auto& c : s) {
    if (c == '0') {
      cout << 1 << ' ' << (t%4)+1 << endl;
      t++;
    } else {
      cout << 3 << ' ' << (b%4)+1 << endl;
      b+=2;
    }
  }
}

