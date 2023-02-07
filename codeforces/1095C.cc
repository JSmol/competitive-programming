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

int n, k;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(k, 1);

  n -= k;
  for (int i = 0; i < k and n > 0; i++) {
    n--;
    A[i]++;
    int j = 1;
    while (n - (1 << j) >= 0) n -= (1 << j), A[i] += (1 << j), j++;
  }

  if (n != 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl << A << endl;
}

