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

int n, m, k;
vector<int> A, B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  A.assign(n, 0);
  B.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (i > 0)
      B[i] = A[i] - A[i-1];
  }

  sort(begin(B), end(B));
  int ans = n;
  int i = 1;
  while (n > k) {
    ans += B[i] - 1;
    i++;
    n--;
  }

  cout << ans << endl;

}

