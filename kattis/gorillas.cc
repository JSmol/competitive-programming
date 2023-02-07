#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
double time() { return double(clock()) / CLOCKS_PER_SEC; }
#define double long double

const int MAX_N = 3;

int LU_decomp(double A[MAX_N][MAX_N], int n, int pivot[], double &det)
{
  double s[MAX_N];           /* factors used in implicit scaling */
  double c, t;
  int i, j, k;

  det = 1.0;

  /* compute s[i] */
  for (i = 0; i < n; i++) {
    s[i] = 0.0;
    for (j = 0; j < n; j++) {
      if ((t = fabs(A[i][j])) > s[i]) {
	s[i] = t;
      }
    }
    if (s[i] == 0.0) {
      /* a row of zeroes: singular */
      det = 0.0;
      return 0;
    }
  }
  
  /* do the row reductions */
  for (k = 0; k < n-1; k++) {
    c = fabs(A[k][k]/s[k]);
    pivot[k] = k;
    for (i = k+1; i < n; i++) {
      t = fabs(A[i][k]/s[i]);
      if (t > c) {
	c = t;
	pivot[k] = i;
      }
    }

    if (c == 0) {
      /* pivot == 0: singular */
      det = 0.0;
      return 0;
    }

    /* do row exchange */
    if (k != pivot[k]) {
      det *= -1.0;
      for (j = k; j < n; j++) {
	t = A[k][j];
	A[k][j] = A[pivot[k]][j];
	A[pivot[k]][j] = t;
	t = s[k];
	s[k] = s[pivot[k]];
	s[pivot[k]] = t;
      }
    }

    /* do the row reduction */
    for (i = k+1; i < n; i++) {
      A[i][k] /= A[k][k];
      for (j = k+1; j < n; j++) {
	A[i][j] -= A[i][k] * A[k][j];
      }
    }

    det *= A[k][k];
  }
  
  /* note that the algorithm as state in the book is incorrect.  The */
  /* following is need to ensure that the last row is not all 0's.   */
  /* (maybe the book is correct, depending on what you think it's    */
  /* supposed to do.)                                                */
  if (A[n-1][n-1] == 0.0) {
    det = 0.0;
    return 0;
  } else {
    det *= A[n-1][n-1];
    return 1;
  }
}

void LU_solve(double A[MAX_N][MAX_N], int n, int pivot[], double b[], 
	      double x[])
{
  double t;
  int i, j, k;

  for (i = 0; i < n; i++) {
    x[i] = b[i];
  }
  for (k = 0; k < n-1; k++) {
    /* swap if necessary */
    if (k != pivot[k]) {
      t = x[k];
      x[k] = x[pivot[k]];
      x[pivot[k]] = t;
    }
    
    for (i = k+1; i < n; i++) {
      x[i] -= A[i][k] * x[k];
    }
  }

  x[n-1] /= A[n-1][n-1];
  
  for (i = n-2; i >= 0; i--) {
    for (j = i+1; j< n; j++) {
      x[i] -= A[i][j] * x[j];
    }
    x[i] /= A[i][i];
  }
}

int haha(int n, int m, vector<vector<double>> Q, vector<double> P, vector<double>& ans) {
  double A[MAX_N][MAX_N], x[MAX_N], b[MAX_N];
  int pivot[MAX_N];             /* only n-1 is needed, but what the heck */
  int i, j;
  double det;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      A[i][j] = Q[i][j];
    b[i] = P[i];
  }
  
  LU_decomp(A, n, pivot, det);
  LU_solve(A, n, pivot, b, x);
    
  ans = { x[0], x[1], x[2] };
  return 1;
}


// solve Ax = b
const double eps = 1e-12;
int solve(int n, int m, vector<vector<double>> A, vector<double> b, vector<double>& ans) {
  for (int r = 0, c = 0; r < n and c < m; c++, r++) {
    int pv = r;
    for (int i = r; i < n; i++) if (abs(A[pv][c]) < abs(A[i][c])) pv = i;
    if (abs(A[pv][c]) < eps) return 0;
    swap(A[pv], A[r]); swap(b[pv], b[r]);
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
  int T; cin >> T;
  for (int C = 1; C <= T; C++) {

    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }

    double ans = max(y1, y2);
    double m = (y2-y1)/(x2-x1);
    double b = y1 - m*x1;
    for (int i = 0; i < n; i++) {
      if (y[i] - (m*x[i] + b) > eps) {
        ans = 1ll << 30; // points above
        goto loop;
      }
    }

    goto done;

loop:
    for (int i = 0; i < n; i++) {

      if ((m*x[i] + b) - y[i] > eps) continue; // point is below

      vector<vector<double>> X = {
        { x1 * x1, x1, 1.0 },
        { x2 * x2, x2, 1.0 },
        { x[i] * x[i], x[i], 1.0 },
      };

      vector<double> Y = {
        y1, y2, y[i]
      };

      vector<double> r;
      int z = haha(3, 3, X, Y, r);

      assert(z == 1);

      double x0 = -r[1]/(2.0*r[0]);
      double y0 = r[0]*x0*x0 + r[1]*x0 + r[2];

      for (int j = 0; j < n; j++) {
        if (y[j] - (r[0]*x[j]*x[j] + r[1]*x[j] + r[2]) > eps) {
          goto nxt;
        }
      }
    
      if (x1 < x0 and x0 < x2)
        ans = min(ans, max({y0, y1, y2}));
      else 
        ans = min(ans, max({y1, y2}));
nxt:;
    }

done:;
    // assert(ans - max(y1, y2) > -eps);
    // assert(ans < 1ll << 40);
    cout << fixed << setprecision(9) << ans << endl;
  }
}

