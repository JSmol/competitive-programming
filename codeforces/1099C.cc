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

int n, m, k, c, f;
string s, ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  cin >> k;
  c = count(begin(s), end(s), '?');
  f = count(begin(s), end(s), '*');
  n = s.size() - f - c;

  int i = 0;
  while (i < n+f+c) {
    if (s[i] != '?' and s[i] != '*') {
      ans += s[i];
      i++;

      continue;
    }

    if (n+m < k and s[i] == '*') {
      while (n+m < k) {
        ans += ans.back();
        m++;
      }
    }

    if (n+m > k) {
      ans.pop_back();
      m--;
    }
  
    i++;
  }

  if (ans.size() == k)
    cout << ans << endl;
  else
    cout << "Impossible" << endl;
  
}

