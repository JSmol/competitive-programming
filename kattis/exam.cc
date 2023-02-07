#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n;
string s, t;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  cin >> s >> t;

  int m = (int) s.length();
  int c = 0;
  for (int i = 0; i < m; i++)
    if (s[i] == t[i])
      c++;
  
  if (c > n)
    cout << m - (c - n) << endl;
  else
    cout << m - (n - c) << endl;

}

