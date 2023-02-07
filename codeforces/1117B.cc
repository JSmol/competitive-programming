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
ll n, m, k, a, b;
vector<ll> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  A.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (a <= A[i]) {
      b = a;
      a = A[i];
    } else if (b <= A[i]) {
      b = A[i];
    }
  }

  ll ans = (m / (k+1)) * k * a;
  ans += (m / (k+1)) * b;
  ans += (m % (k+1)) * a;
  cout << ans << endl;
  
}

