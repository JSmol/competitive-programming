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
string s;
const string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int f(char c) {
  return a[(a.find(c) + n) % 28];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  while (cin >> n and n > 0) {
    cin >> s;
    reverse(begin(s), end(s));
    string ans = "";
    for (auto& c : s) {
      ans += f(c);
    }
    cout << ans << endl;
  }
}

