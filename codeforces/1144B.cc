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

int n, e, o, ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a, a % 2 ? o++ : e++;

  sort(all(A));
  if (e < o) o -= e+1, e = 0;
  if (e > o) e -= o+1, o = 0;
  if (e == o) e = o = 0;

  for (int i = 0; i < n and (e > 0 or o > 0); i++) {
    if (e > 0 and A[i] % 2 == 0) ans += A[i], e--;
    if (o > 0 and A[i] % 2 != 0) ans += A[i], o--;
  }

  cout << ans << endl;
}

