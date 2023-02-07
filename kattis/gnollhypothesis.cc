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

void f(vector<double>& A, int n) {
  for (auto& a : A) cout << 100.0 / n << ' ';
  cout << endl;

  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << setprecision(9) << fixed;
  int n, k; cin >> n >> k;
  vector<double> A(n);
  for (auto& a : A) cin >> a;
  if (k == 1) f(A, n);

  vector<vector<double>> X(n+1, vector<double>(n+1));
  X[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      X[i][j] = (j ? X[i-1][j-1] : 0) + X[i-1][j];
    }
  }

  vector<double> ans(n);
  for (int i = 0; i < n; i++) {

    vector<double> p(n);
    for (int l = 0; l < n; l++) {
      if (n - l - 2 < 0) p[l] = 0;
      else {
        if ((n + i - l - 1) % n != i) {
          p[l] = X[n - l - 2][k - 2] / X[n][k];
        } else {
          p[l] = 1.0 / X[n][k];
        }
      }
    }

    for (int l = 0; l < n; l++) {
      double s = 0;
      for (int j = 0; j <= l; j++) {
        s += A[(n+i-j) % n];
      }

      ans[i] += p[l] * s;
    }
  }

  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

