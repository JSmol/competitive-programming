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

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
  if (a.fst == 0) return 1;
  if (b.fst == 0) return 0;
  if (a.snd == 0) return 0;
  if (b.snd == 0) return 1;

  return a.fst*b.snd < a.snd*b.fst;
}

ll f(ll x) {
  return (x*(x-1))/2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;

  vector<pair<ll, ll>> A(n);
  for (auto& a : A) {
    cin >> a.fst >> a.snd;
  }

  set<ll> V, H;
  map<pair<ll, ll>, set<pair<ll, ll>>> S;
  
  for (ll i = 0; i < n; i++) {
    auto& a = A[i];
    for (ll j = i+1; j < n; j++) {
      auto& b = A[j];

      ll x = a.fst-b.fst;
      ll y = a.snd-b.snd;
      if (x == 0 or y == 0) {
        if (x == 0) V.insert(a.fst);
        if (y == 0) H.insert(a.snd);
      } else {
        ll d = __gcd(x, y);
        pair<ll, ll> p = {y/d, x/d};
        if (S.count(p)) {
          bool o = false;
          for (auto& q : S[p]) {
            if (p.snd*a.snd - p.fst*a.fst == p.snd*q.snd - p.fst*q.fst) {
              o = true;
              break;
            }
          }

          if (!o) S[p].insert(a);

        } else {
          // a.snd = m a.fst + b
          S.insert({p, {a}});
        }
      }
    }
  }

  ll l = V.size() + H.size();
  for (auto& s : S) {
    l += s.snd.size();
  }

  ll ans = f(l);
  ans -= f(V.size());
  ans -= f(H.size());
  for (auto& s : S) {
    ans -= f(s.snd.size());
  }

  cout << ans << endl;
}

