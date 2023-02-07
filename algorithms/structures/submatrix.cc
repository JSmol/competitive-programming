template<typename T>
struct submatrix {
  int R, C; vector<vector<T>> p;
  submatrix(vector<vector<T>>& v, int R, int C) : p(R, vector<int>(C)), R(R), C(C) {
    for (int r = 0; r < R; r++) 
      for (int c = 0; c < C; c++) 
        p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
  }
  T sum(int u, int l, int d, int r) {
    assert(0 <= u and 0 <= l and d < R and r < C);
    return p[d][r] - p[d][l] - p[u][r] + p[u][l];
  }
};
