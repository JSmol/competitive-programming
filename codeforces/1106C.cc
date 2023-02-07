#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

typedef long long ll;
ll n;
vector<ll> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  sort(begin(A), end(A));
  ll s = 0;
  for (int i = 0; i < n/2; i++)
    s += (A[i] + A[(n-1)-i]) * (A[i] + A[(n-1)-i]);

  cout << s << endl;
}

