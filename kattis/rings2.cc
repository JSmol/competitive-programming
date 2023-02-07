#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int n, m;
int A[111][111];
int C[111][111];

int f(int i, int j, int r) {
  for (int k : {-1, 1}) {
    if (A[i+k][j] == r) return true;
    if (A[i][j+k] == r) return true;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      cin >> x;
      A[i][j] = (x == '.' ? 0 : -1);
    }
  }

  int l = 0;
  for (int r = 1; r <= max(n, m); r++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        C[i][j] = -1;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (A[i][j] == -1 and f(i, j, r-1)) {
          C[i][j] = r;
          l = r;
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (C[i][j] != -1)
          A[i][j] = C[i][j];
      }
    }
  }

  if (l < 10) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (A[i][j] == 0) cout << "..";
        else cout << "." << A[i][j];
      }
      cout << endl;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (A[i][j] == 0) cout << "...";
        else if (A[i][j] < 10) cout << ".." << A[i][j];
        else cout << "." << A[i][j];
      }
      cout << endl;
    }
  }
}

