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
vector<int> A, B, K;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  A.assign(n, 0);
  B.assign(n, 0);
  K.assign(k, 0);
  for (auto& a : A) cin >> a;
  for (auto& a : B) cin >> a;
  for (auto& a : K) cin >> a, a--;

  int ans = 0;
  for (auto& a : K) {
    for (int i = 0; i < n; i++) {
      if (i == a) continue;
      if (B[i] == B[a] and A[i] > A[a]) {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
}

