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
int C[1010], U[1010];
int A[20][20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0, a; i < n*n; i++) cin >> a, C[a]++, m = max(a, m);

  for (int r = 0; r < n/2; r++) {
    for (int c = 0; c < n/2; c++) {
      for (int i = 1; i <= m; i++) {
        if (C[i] - U[i] >= 4) {
          A[r][c] = A[n-r-1][n-c-1] = A[r][n-c-1] = A[n-r-1][c] = i;
          U[i] += 4;
          break;
        }
      }
    }
  }

  if (n % 2 != 0) {
    int mid = n/2;
    for (int i = 0; i < n/2; i++) {
      for (int j = 1; j <= m; j++) {
        if (C[j] - U[j] >= 2) {
          A[mid][i] = A[mid][n-i-1] = j;
          U[j] += 2;
          break;
        }
      }
    }

    for (int i = 0; i < n/2; i++) {
      for (int j = 1; j <= m; j++) {
        if (C[j] - U[j] >= 2) {
          A[i][mid] = A[n-i-1][mid] = j;
          U[j] += 2;
          break;
        }
      }
    }

    for (int j = 1; j <= m; j++) {
      if (C[j] - U[j] >= 1) {
        A[mid][mid] = j;
        U[j]++;
        break;
      }
    }
  }

  bool no = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == 0)
        no = true;
    }
  }

  if (no) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << A[i][j] << ' ';
      }
      cout << endl;
    }
  }
}
