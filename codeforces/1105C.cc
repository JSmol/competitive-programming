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
const ll mod = 1000000007;
ll n, l, r;
ll c[3];
ll dp[202020][3];

ll f(ll m, ll o) {
  if (m == 1) return c[o];

  ll& x = dp[m][o];
  if (x != -1) return x;

  if (o % 3 == 0)
    x = f(m-1, 0) * f(1, 0) + f(m-1, 2) * f(1, 1) + f(m-1, 1) * f(1, 2);

  if (o % 3 == 1)
    x = f(m-1, 2) * f(1, 2) + f(m-1, 0) * f(1, 1) + f(m-1, 1) * f(1, 0);

  if (o % 3 == 2)
    x = f(m-1, 1) * f(1, 1) + f(m-1, 2) * f(1, 0) + f(m-1, 0) * f(1, 2);

  x %= mod;
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> l >> r;
  
  c[0] = c[1] = c[2] = (r - l + 1) / 3;
  if ((r - l + 1) % 3 != 0) 
    for (int i = r; i % 3 != (l-1)%3 and i >= l; i--)
      c[i%3]++;

  for (int i = 0; i <= n; i++)
    fill(dp[i], dp[i]+3, -1);
  
  cout << f(n, 0) << endl;
}

