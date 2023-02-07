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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> A(n), B(n);
  vector<pair<ll, ll>> D(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
    D[i].fst = A[i] - B[i];
    D[i].snd = i;
  }

  ll ans = 0;
  sort(all(D), greater<pair<ll, ll>>());
  for (int i = 0; i < n; i++) {
    ans += A[D[i].snd] * i;
    ans += B[D[i].snd] * (n-i-1);
  }

  cout << ans << endl;
}

