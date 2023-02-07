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

char h(int x) {
  if (x == 0) return 'R';
  if (x == 1) return 'G';
  if (x == 2) return 'B';
}

char g(int x) {
  if (x == 0) return 'R';
  if (x == 2) return 'G';
  if (x == 1) return 'B';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;

  string t(n, 'x');
  pair<int, string> ans = {1<<30, t};
  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++)
      for (int j = k; j < n; j+=3)
        t[j] = h((i+k)%3);

    int b = 0;
    for (int j = 0; j < n; j++)
      if (t[j] != s[j])
        b++;

    debug(t);
    if (b < ans.fst)
      ans = {b, t};
  }

  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++)
      for (int j = k; j < n; j+=3)
        t[j] = g((i+k)%3);

    int b = 0;
    for (int j = 0; j < n; j++)
      if (t[j] != s[j])
        b++;

    debug(t);
    if (b < ans.fst)
      ans = {b, t};
  }

  cout << ans << endl;
}

