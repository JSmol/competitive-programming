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
vector<int> A, S;
int C[2][1200000];

int f(int x) {
  if (x == 1) return 0;
  return (x*(x-1)) / 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  S.assign(n+1, 0);
  for (int i = 0; i < n; i++) cin >> A[i], S[i+1] = S[i] ^ A[i];

  for (auto& s : S) {
    C[0][s]++;
  }

  int ans = 0;
  for (int j = 0; j < 1; j++) {
    for (int i = 0; i < 1200000; i++) {
      if (C[j][i] > 0) {
        ans += f(C[j][i]);
      }
    }
  }

  cout << ans << endl;
}

