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
ll n, d;
vector<ll> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> d;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  sort(all(A));
  map<ll, ll> M;
  for (int i = 0; i < n; i++) {
    ll v = A[i] / d;
    if (M.count(v)) M[v]++;
    else M[v] = 1;
  }

  ll ans = 0;
  for (auto& m : M) {
    ans += (m.snd * (m.snd - 1)) / 2;
  }

  cout << ans << endl;
}

