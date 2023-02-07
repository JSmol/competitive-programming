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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
ll mod = 1000000007;
ll fexp(ll m, ll p) {
  ll r = 1; ll x = m;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m;
  cin >> n >> m;
  cout << fexp(fexp(2, m) - 1, n) << endl;
}

