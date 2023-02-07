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

int n, m;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  cin >> A[0];
  for (int i = 1, x; i < n; i++) cin >> x, A[i] = A[i-1]+x;

  cin >> m;
  for (int  i = 0, x; i < m; i++) {
    cin >> x;
    cout << (lower_bound(begin(A), end(A), x) - begin(A))+1<< endl;
  }
}

