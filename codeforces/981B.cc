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
  vector<pair<ll, ll>> A(n);
  for (auto& a : A) cin >> a.fst >> a.snd;
  ll m;
  cin >> m;
  vector<pair<ll, ll>> B(m);
  for (auto& b : B) cin >> b.fst >> b.snd;

  sort(all(A));
  sort(all(B));
  ll i = 0; ll j = 0; ll ans = 0;
  while (i < n and j < m) {
    if (A[i].fst == B[j].fst) {
      ans += max(A[i].snd, B[j].snd);
      i++; j++;
    } else {
      if (A[i].fst < B[j].fst) {
        ans += A[i].snd;
        i++;
      } else {
        ans += B[j].snd;
        j++;
      }
    }
  }

  while (i < n) ans += A[i].snd, i++;
  while (j < m) ans += B[j].snd, j++;
  cout << ans << endl;
}

