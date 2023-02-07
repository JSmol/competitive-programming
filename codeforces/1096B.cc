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

typedef long long ll;
const ll MOD = 998244353;
ll n, i;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s;

  char a = s[0], b = s[n-1];
  ll ans = 1, l = 1, r = 1;

  i = 0;
  while (++i < n and s[i] == a)
    l++;

  i = n - 1;
  while (--i >= 0 and s[i] == b)
    r++;

  if (a == b and l == n-1 and r == n-1)
    ans = ((n + 1) * n) / 2;
  else if (a == b)
    ans = (l + 1) * (r + 1);
  else
    ans += l + r;

  cout << ans % MOD << endl;
}

