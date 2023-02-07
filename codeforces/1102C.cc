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

int n, x, y;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> x >> y;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  sort(begin(A), end(A));

  int ans = 0;
  if (x > y) ans = n;

  if (x == y) {
    int i = 0;
    while (A[i] <= x) i++;
    ans = (i+1) / 2;
  } 

  if (x < y) {
    int i = 0;
    while (A[i] <= x) i++;
    for (int j = i-1, p = 0; j >= 0; j--, p++) {
      if (p % 2 and A[j] + y > x)
        continue;
      else
        ans++;
    }
  }

  cout << ans << endl;
}

