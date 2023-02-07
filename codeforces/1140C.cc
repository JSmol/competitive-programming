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

typedef unsigned long long ll;
ll n, k;
vector<pair<ll, ll>> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, {});
  for (auto& a : A) cin >> a.snd >> a.fst;

  sort(all(A));
  reverse(all(A));

  set<ll> S;
  ll ans = 0, s = 0;
  for (int i = 0; i < n; i++) {
    if (S.size() < k) {
      ans = max(ans, (s + A[i].snd) * A[i].fst);
      s += A[i].snd;
      S.insert(A[i].snd);
    } else if (*begin(S) < A[i].snd) {
      ans = max(ans, (s - *begin(S) + A[i].snd) * A[i].fst);
      s += A[i].snd;
      s -= *begin(S);
      S.erase(begin(S));
      S.insert(A[i].snd);
    } else {
      ans = max(ans, (s - *begin(S) + A[i].snd) * A[i].fst);
    }
  }

  cout << ans << endl;
}

