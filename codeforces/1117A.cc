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
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    m = max(m, A[i]);
  }

  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    if (A[i] == m) {
      while (j < n and A[j] == m) j++;

      if (j - i > ans)
        ans = (j-1)-i;

      continue;
    }
    j++;
  }

  cout << ans + 1 << endl;
}

