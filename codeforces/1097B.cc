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
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  sort(begin(A), end(A));

  for (int i = 0; i < (1 << n); i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        s += A[j];
      } else {
        s -= A[j];
      }
    }

    if (s % 360 == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}

