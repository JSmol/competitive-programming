#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

vector<int> A, B;
int n, m, l, q;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> l;
  A.assign(n+1, 0);
  B.assign(n+2, 0);
  for (int i = 1; i <= n; i++) cin >> A[i], B[i] = A[i] > l;

  bool p = false;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (B[i] and !p)
      c++, p = !p;
    else 
      p = B[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> q;
    if (q) {
      int j, k;
      cin >> j >> k;
      A[j] += k;
      if (!B[j] and A[j] > l) {
        B[j] = 1;
        if (!B[j-1] and !B[j+1])
          c++;
        if (B[j-1] and B[j+1])
          c--;
      }
    } else {
      cout << c << '\n';
    }
  }
}
