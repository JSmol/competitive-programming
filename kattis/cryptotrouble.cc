#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

typedef long long ll;
ll mod = 1000000007;
string s, t;
ll n;
ll dp[202020][3];

ll f(ll i, ll j) {
  ll& x = dp[i][j];
  if (x != -1) return x;

  if (i == n) return x = (j == 0);

  ll k = (t[i]-'0') % 3;
  x = f(i+1, (j+k)%3) + f(i+1, j);

  return x = (x % mod);
}

ll z;

ll g() {
  ll r = 1;
  while (0 < z--) 
    r = (2*r)%mod;
  return r - 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s;

  for (auto c : s) {
    if (c == '0') {
      z++; n--;
    } else {
      t+=c;
    }
  }

  for (ll i = 0; i <= n; i++)
    for (ll j = 0; j < 3; j++)
      dp[i][j] = -1;
  
  ll ans = f(0, 0) - 1;
  cout << (ans * (g()+1)) % mod << endl;
}

