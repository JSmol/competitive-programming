#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

const int maxn = 202020;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  vector<vector<int>> D(maxn);
  for (int i = 0; i < n; i++) {
    cin >> A[i]; int x = 0;
    while (A[i]) D[A[i]].push_back(x), A[i] /= 2, x++;
    D[0].push_back(x);
  }

  int ans = 1<<30;
  for (int i = 0; i < maxn; i++) {
    if (sz(D[i]) < k) continue;
    sort(all(D[i])); int s = 0;
    for (int j = 0; j < k; j++) s += D[i][j];
    ans = min(ans, s);
  }

  cout << ans << endl;
}

