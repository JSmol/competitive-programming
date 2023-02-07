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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> A(n), P(n);
  iota(all(A), 0); iota(all(P), 0);
  vector<pair<int, int>> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = {P[i], P[i]};
  }

  for (int i = 0, x; i < m; i++) {
    cin >> x; x--;
    if (P[x] != 0) {
      int y = A[P[x] - 1];
      swap(A[P[x]], A[P[y]]);
      P[x]--;
      P[y]++;
      ans[x].fst = min(ans[x].fst, P[x]);
      ans[y].snd = max(ans[y].snd, P[y]);
    }
  }

  for (auto& a : ans) {
    cout << a.fst+1 << ' ' << a.snd+1 << endl;
  }
}

