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
vector<int> A, ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  sort(begin(A), end(A));
  reverse(begin(A), end(A));
  ans.assign(n, 0);
  if (n % 2 == 0) {
    int m = n/2;
    for (int i = 0; i < n; i++) {
      if (i%2 == 0)
        ans[m-(i/2)-1] = A[i];
      else
        ans[m+(i/2)] = A[i];
    }
  } else {
    int m = n/2;
    ans[m] = A[0];
    for (int i = 1; i < n; i++) {
      if (i%2 == 0) {
        ans[m+(i/2)] = A[i];
      } else {
        ans[m-(i/2)-1] = A[i];
      }
    }
  }

  cout << ans << endl;
}

