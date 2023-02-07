#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

typedef long long ll;
int n;

ll f(int m) {
  ll x = 0;
  int i = 2;
  set<int> D;
  while (i * i <= m) {
    if (m % i == 0) {
      D.insert(i);
      D.insert(m / i);
    }
    i++;
  }

  for (auto& d : D)
    x += (m / d) * 4ll;

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;
  ll ans = 0;
  for (int i = 4; i <= n; i++)
    ans += f(i);

  cout << ans << endl;
}

