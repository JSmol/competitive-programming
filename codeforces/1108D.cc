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

char g(int x) {
  if (x == 0) return 'R';
  if (x == 1) return 'G';
  if (x == 2) return 'B';
}

int h(char x) {
  if (x == 'R') return 0;
  if (x == 'G') return 1;
  if (x == 'B') return 2;
}

int f(char x, char y) {
  for (int i = 0; i < 3; i++)
    if (h(x) != i and h(y) != i)
      return i;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;

  string t = s;
  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    while (s[i] == s[j]) j++;

    if ((j-i) % 2 == 0) {
      ans += (j-i) / 2;

      int c;
      if (i-1 < 0)
        c = g((h(s[i])+1)%3);
      else 
        c = g(f(s[i-1], s[i]));

      for (int k = i; k < j; k+=2)
        t[k] = c;

    } else {
      ans += (j-i) / 2;
      for (int k = i + 1; k < j; k+=2)
        t[k] = g((h(s[i])+1)%3);
    }
  }

  cout << ans << endl;
  cout << t << endl;
}

