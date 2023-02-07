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

int n, k, s;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a, s += a;

  int ans = 0;
  for (int i = 0; i < k; i++) {
    int d = 0;
    for (int j = i; j < n; j+=k)
      d += A[j];

    ans = max(ans, abs(s - d));
  }
  cout << ans << endl;
}

