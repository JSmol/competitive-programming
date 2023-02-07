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

typedef long long ll;
ll n, g;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> g;
  vector<pair<ll, ll>> A(n);
  for (auto& a : A) cin >> a.fst >> a.snd;
  A.push_back({0,0}); n++;
  sort(all(A));
  // debug(A);

  multiset<ll> S;
  ll ans = 0, i = 0, j = 0;
  for (int k = 0; k < n-1; k++) {
    if (A[i].fst <= g) S.insert(A[i].snd), i++;
    if (A[k+1].fst - A[k].fst > g) {
      cout << "cancel road trip" << endl;
      return 0;
    }
  }

  i--;
  ll l = g;
  while (l < A[n-1].fst) {
    // debug(i);
    // debug(j);
    // debug(l);
    // debug(ans);
    // debug(A[j].fst + g);
    // debug(A[i+1].fst);

    if (A[j].fst + g < A[i+1].fst) {
      ans += (*begin(S)) * (A[j].fst + g - l);
      S.erase(S.find(A[j].snd));
      l = A[j].fst + g; j++;
    } else {
      ans += (*begin(S)) * (A[i+1].fst - l);
      S.insert(A[i+1].snd);
      l = A[i+1].fst; i++;
    }
  }
  cout << ans << endl;
}

