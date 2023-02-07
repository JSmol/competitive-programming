#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int n, m;
vector<vector<int>> A, B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, vector<int>(m));
  B.assign(n, vector<int>(m));
  for (auto& r : A)
    for (auto& c : r)
      cin >> c;

  for (auto& r : B)
    for (auto& c : r)
      cin >> c;

  for (int k = 0; k < 2*n; k++) {
    multiset<int> S, T;
    for (int i = 0; i < n; i++) {
      int j = k - i;
      if (j < 0 or j >= n) continue;

      S.insert(A[i][j]);
      T.insert(B[i][j]);
    }

    if (S != T) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}

