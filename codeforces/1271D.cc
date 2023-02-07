#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

const int inf = (1<<30);
int n, m, k;
int A[5050];
int B[5050];
int C[5050];
int L[5050];
int dp[5050][5050];
vector<int> X[5050];

int f(int i, int a) {
  if (a < A[i]) return -inf;
  if (i == n) return 0;

  int& x = dp[i][a];
  if (x != -1) return x;

  int s = 0;
  x = f(i+1, a + B[i]);
  for (int j = 0; j < sz(X[i]); j++) {
    s += C[X[i][j]];
    a--;
    x = max(x, f(i+1, a + B[i]) + s);
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i] >> C[i];
    L[i] = i;
  }

  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b; a--; b--;
    L[b] = max(L[b], a);
  }

  for (int i = 0; i < n; i++) {
    X[L[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    sort(all(X[i]), [&] (int i, int j) { return C[i] > C[j]; });
  }

  for (int i = 0; i < 5050; i++) fill(dp[i], dp[i]+5050, -1);
  cout << (f(0, k) < 0 ? -1 : f(0, k)) << endl;
}

