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
  int n = s.size(), i = 0, p = 0;
  while (i < n) {
    if (i < n-1 and s[i] == s[i+1]) {
      s.erase(i, 2);
      p++; i--; n-=2;
      continue;
    }
    i++;
  }

  if (p % 2 == 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

}

