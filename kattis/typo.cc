#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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
const ll p1 = 1e9+7, p2 = 1e9+9;
const ll a = 27;

pair<ll, ll> egcd(ll a, ll b) {
  if (b > a) swap(a, b);
  ll s = 0, t = 1, u = 1, v = 0, q = 0;
  while (b != 0) {
    q = a/b;
    swap(a, b);
    b = b % a;
    swap(s, u);
    s = s - u * q;
    swap(t, v);
    t = t - v * q;
  }
  return {u, v};
}

ll modinv(ll a, ll m) {
  return (egcd(a, m).snd + m) % m;
}

const ll inv1 = modinv(27, p1);
const ll inv2 = modinv(27, p2);

ll fexp(ll x, ll p, ll mod) {
  ll r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

ll f(char c) {
  return c - 'a' + 1;
}

ll shash1(string s) {
  ll v = 0;
  for (int i = 0; i < s.length(); i++)
    v = (v + f(s[i]) * fexp(a, i, p1)) % p1;
  return v % p1;
}

ll shash2(string s) {
  ll v = 0;
  for (int i = 0; i < s.length(); i++)
    v = (v + f(s[i]) * fexp(a, i, p2)) % p2;
  return v % p2;
}

vector<string> A;
set<pair<ll, ll>> S;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  A.assign(n, {});
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    S.insert({shash1(A[i]), shash2(A[i])});
  }

  // h = s0*a^0 + s1*a^1 + s2*a^2 + ... + sn*a^n
  vector<string> ans;
  for (auto& s : A) {
    ll h1 = (((inv1 * (shash1(s) - f(s[0]))) % p1) + p1) % p1;
    ll h2 = 0;
    ll k1 = (((inv2 * (shash2(s) - f(s[0]))) % p2) + p2) % p2;
    ll k2 = 0;

    if (S.count({h1, k1})) {
      ans.push_back(s);
      continue;
    }

    for (int i = 1; i < s.size(); i++) {
      h1 = (((inv1 * (h1 - f(s[i]))) % p1) + p1) % p1;
      h2 = (((h2 + f(s[i-1])*fexp(a, i-1, p1)) % p1) + p1) % p1;
      ll hs = h2 + h1 * fexp(a, i, p1);
      k1 = (((inv2 * (k1 - f(s[i]))) % p2) + p2) % p2;
      k2 = (((k2 + f(s[i-1])*fexp(a, i-1, p2)) % p2) + p2) % p2;
      ll ks = k2 + k1 * fexp(a, i, p2);
      if (S.count({((hs % p1) + p1) % p1, ((ks % p2) + p2) % p2})) {
        ans.push_back(s);
        break;
      }
    }
  }

  if (ans.empty()) {
    cout << "NO TYPOS" << endl;
  } else {
    for (auto& a : ans) cout << a << endl;
  }
}

