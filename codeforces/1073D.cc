#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll n, t;
vector<ll> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> t;
  A.assign(n, 0);
  for (auto& a : A) 
    cin >> a;

  ll ans = 0;
  while (true) {
    ll s = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (t >= s + A[i])
        s += A[i], c++;
    }

    if (!c or !s) break;
    ans += c * (t / s);
    t = t % s;
  }

  cout << ans << endl;

}