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
int A[1010][1010];
int B[1010][1010];
int C[1010][1010];
vector<set<int>> V, H;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  V.assign(m, {});
  H.assign(n, {});
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
      V[j].insert(A[i][j]);
      H[i].insert(A[i][j]);
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      B[i][j] = distance(H[i].begin(), H[i].lower_bound(A[i][j]));
    }
  }

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      C[i][j] = distance(V[i].begin(), V[i].lower_bound(A[j][i]));
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cout << (max(B[i][j], C[j][i]) + max(H[i].size() - B[i][j], V[j].size() - C[j][i])) << ' ';
    }
    cout << endl;
  }
}

