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

int triangulate(int A[22][44], int m, int n, int cols) {
  div_t d;
  int ri = 0, ci = 0;
  while (ri < m and ci < cols) {
    int pi = -1;
    for (int i = ri; i < m; i++)
      if (A[i][ci] and (pi == -1 or abs(A[i][ci]) < abs(A[pi][ci]))) pi = i;
    if (pi == -1) ci++;
    else {
      int k = 0;
      for (int i = ri; i < m; i++) {
        if (i != pi) {
          d = div(A[i][ci], A[pi][ci]);
          if (d.quot) {
            k++;
            for (int j = ci; j < n; j++) A[i][j] -= d.quot*A[pi][j];
          }
        }
      }
      if (!k) {
        for (int i = ci; i < n and ri != pi; i++) swap(A[ri][i], A[pi][i]);
        ri++; ci++;
      }
    }
  }
  return ri;
}

int dlinsolve(int A[22][22], int b[22], int m, int n, int xp[22], int homb[22][22]) {
  int mat[22][44], i, j, rank, d;
  for (i = 0; i < m; i++) mat[0][i] = -b[i];
  for (i = 0; i < m; i++) for (j = 0; j < n; j++) mat[j+1][i] = A[i][j];
  for (i = 0; i< n+1; i++) for (j = 0; j < n+1; j++) mat[i][j+m] = (i==j);
  rank = triangulate(mat, n+1, m+n+1, m+1);
  d = mat[rank-1][m];
  if (d != 1 and d != -1) return -1;

  for (i = 0; i < m; i++)
    if (mat[rank-1][i]) return -1;

  for (i = 0; i < n; i++) {
    xp[i] = d*mat[rank-1][m+1+i];
    for (j = 0; j < n+1-rank; j++) homb[i][j] = mat[rank+j][m+1+i];
  }
  return n+1-rank;

}

int A[22][22], b[22], xp[22], homb[22][22];
int n, m;
map<string, int> M;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  while (getline(cin, s)) {
    if (s[0] == '0') break;
    stringstream ss(s);
    char sgn;
    int sg, e;
    ss >> sgn >> sg >> e;
    for (int j = 0; j < e; j++) {
      string x; int c;
      ss >> x >> c;

      if (!M.count(x)) M[x] = m++;
      A[M[x]][n] += (sgn == '-' ? -1 : 1)*c;
    }
    
    n++;
  }
  
  debug(dlinsolve(A, b, m, n, xp, homb));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      xp[i] += homb[i][j];
  }

  for (int i = 0; i < n; i++)
    cout << xp[i] << ' ';
  cout << endl;
}

