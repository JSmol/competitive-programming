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

int n, k, x;
string s;
int C[26];

int f(char c) {
  return c - 'a';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  cin >> s;
  char p = '#';
  for (auto c : s) {
    if (c == p) x++;
    else x = 1;

    if (x == k) C[f(c)]++, x = 0;
    p = c;
  }

  int ans = 0;
  for (int i = 0; i < 26; i++)
    ans = max(ans, C[i]);

  cout << ans << endl;
}

