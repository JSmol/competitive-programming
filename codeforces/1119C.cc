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

int n, m, s;
int A[505][505], B[505][505], R[505], C[505];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> A[i][j], R[i] += A[i][j], C[j] += A[i][j];
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> B[i][j], R[i] += B[i][j], C[j] += B[i][j], s += A[i][j] != B[i][j];

  bool ans = true;
  for (int i = 0; i < n; i++) if (R[i] % 2) ans = false;
  for (int i = 0; i < m; i++) if (C[i] % 2) ans = false;

  if (!ans) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int r = 0;
    for (int j = 0; j < m; j++) {
      if (A[i][j] != B[i][j]) {
        r++;
      }
    }

    if (r > s) {
      cout << "No" << endl;
      return 0;
    }
  }

  for (int j = 0; j < m; j++) {
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (A[i][j] != B[i][j]) {
        c++;
      }
    }

    if (c > s) {
      cout << "No" << endl;
      return 0;
    }
  }  

  cout << "Yes" << endl;
}

