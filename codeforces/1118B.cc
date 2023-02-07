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

int n;
vector<int> A, E, O;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  E.assign(n, 0);
  O.assign(n, 0);
  for (int i = 0, e = 0, o = 0; i < n; i++) {
    if (i % 2 == 0) 
      e += A[i];
    else 
      o += A[i];
    E[i] = e;
    O[i] = o;
  }

  int ans = 0;
  ans += (E[n-1] - E[0] == O[n-1]);
  ans += (E[n-2] == O[n-2]);
  for (int i = 1, e, o; i < n-1; i++) {
    e = E[i-1] + (O[n-1] - O[i]);
    o = O[i-1] + (E[n-1] - E[i]);
    if (e == o)
      ans++;
  }

  cout << ans << endl;
}

