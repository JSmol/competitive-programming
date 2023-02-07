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
vector<pair<int, int>> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    for (int j = i+1; j <= k; j++) {
      A.push_back({i, j});
      A.push_back({j, i});
      if (A.size() > n) goto end;
    }
  }

end:

  if (A.size() >= n) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      cout << A[i] << endl;
  } else {
    cout << "NO" << endl;
  }
}

