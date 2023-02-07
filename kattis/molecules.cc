#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define all(X) begin(X), end(X)
#define sz(X) (int) X.size()

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

// solve Ax = b
const double eps = 1e-9;
int solve(int n, int m, vector<vector<double>> A, vector<double> b, vector<double>& ans) {
  for (int r = 0, c = 0; r < n and c < m; c++, r++) {
    int pv = r;
    for (int i = r; i < n; i++)
      if (abs(A[pv][c]) < abs(A[i][c])) pv = i;

    if (abs(A[pv][c]) < eps) return 2;
    swap(A[pv], A[r]);
    swap(b[pv], b[r]);

    for (int i = 0; i < n; i++) {
      if (i == r) continue;
      double x = A[i][c] / A[r][c];
      b[i] = b[i] - b[r] * x;
      for (int j = 0; j < n; j++) {
        A[i][j] = A[i][j] - A[r][j] * x;
      }
    }
  }

  ans.assign(m, 0);
  for (int r = 0, c = 0; r < n and c < m; r++) {
    while (c < m and abs(A[r][c]) < eps) c++;
    if (c < m) ans[c] = b[r] / A[r][c];
  }

  for (int r = 0; r < n; r++) {
    double sum = 0;
    for (int c = 0; c < m; c++) sum += A[r][c] * ans[c];
    if (abs(sum - b[r]) > eps) return 0;
  }

  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;

  int k = 0;
  vector<int> x(n), y(n), I(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    if (x[i] == -1 and y[i] == -1) I[i] = k++;
  }

  // x[i] = sum(x[j])/|x|
  vector<vector<int>> A(n);
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b; a--; b--;
    A[a].push_back(b);
    A[b].push_back(a);
  }

  // M[i][j] * x[j] = b[i];
  vector<vector<double>> M1(k, vector<double>(k, 0));
  vector<double> b1(k);
  vector<vector<double>> M2(k, vector<double>(k, 0));
  vector<double> b2(k);

  // x_j = x value of jth thing
  // x_j/A[i].size() = b_i
  for (int i = 0; i < n; i++) {
    if (x[i] == -1 and y[i] == -1) {
      M1[I[i]][I[i]] = -1;
      M2[I[i]][I[i]] = -1;
    } else continue;

    for (auto& a : A[i]) {
      if (x[a] == -1 and y[a] == -1) {
        M1[I[i]][I[a]] = 1.0 / sz(A[i]);
        M2[I[i]][I[a]] = 1.0 / sz(A[i]);
      } else {
        b1[I[i]] -= (double) x[a] / sz(A[i]);
        b2[I[i]] -= (double) y[a] / sz(A[i]);
      }
    }
  }

  vector<double> ans1, ans2;
  solve(k, k, M1, b1, ans1);
  solve(k, k, M2, b2, ans2);

  cout << fixed << setprecision(6);
  for (int i = 0; i < n; i++) {
    if (x[i] == -1 and y[i] == -1) {
      cout << ans1[I[i]] << ' ' << ans2[I[i]] << endl;
    } else {
      cout << x[i] << ' ' << y[i] << endl;
    }
  }
}

