#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
ll mod = 1000000007;
ll l, r;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> l >> r;

  ll o = 0, e = 0, x = 1, i = 1;
  while (x < l) {
    if (i % 2) o += x/2;
    else e += x/2;

    if ((x << 1) < l) x <<= 1;
    else {
      if (i % 2) e += l-x;
      else o += l-x;
      break;
    }
    i++;
  }

  ll s1 = (e*(e+1) + o*o) % mod;

  o = 0, e = 0, x = 1, i = 1;
  while (x < r) {
    if (i % 2) o += x/2;
    else e += x/2;

    if ((x << 1) < l) x <<= 1;
    else {
      if (i % 2) e += r-x+1;
      else o += r-x+1;
      break;
    }
    i++;
  }

  ll s2 = (e*(e+1) + o*o) % mod;
  cout << ((s2 - s1) + mod) % mod << endl;
  debug(o);
  debug(e);
}

