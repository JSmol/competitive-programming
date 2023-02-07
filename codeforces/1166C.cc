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

ll f(ll x) {
  return (x*(x-1))/2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (auto& a : A) cin >> a, a = abs(a);
  
  ll ans = 0;
  sort(all(A));
  for (int i = 0, k = 0; i < n; i++) {
    while (k < n and 2*A[i] >= A[k]) k++;
    ll l = k - i - 1;
    ans += l;
  }
  cout << ans << endl;
}

