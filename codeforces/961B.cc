#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n, k;
vector<int> A, B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  int t = 0;
  B.assign(n, 0);
  for (int i = 0, c = 0, s = 0; i < n; i++) {
    cin >> c;
    s += c ? 0 : A[i];
    t += c ? A[i] : 0;
    B[i] = s;
  }

  int m = B[k-1];
  for (int i = 0; i < n - k; i++)
    m = max(m, B[i+k] - B[i]);

  cout << t + m << endl;
}

