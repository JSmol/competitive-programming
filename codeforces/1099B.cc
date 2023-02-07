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
ll n;

bool f(ll i) {
  ll a = i/2;
  ll b = i/2+(i%2);
  if (a * b >= n)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  ll l = 1, h = 1<<30;
  while (h-l > 1) {
    ll m = (h+l) / 2;
    if (f(m)) h = m;
    else l = m;
  }

  cout << h << endl;
}

