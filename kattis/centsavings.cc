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

int n, d;
int dp[2020][22];
vector<int> A;

int f(int i, int k) {
  if (i == n) return 0;
  if (k == d) return 10*((5+accumulate(begin(A)+i, end(A), 0))/10);

  int& x = dp[i][k];
  if (x != -1) return x;
  x = 1 << 30;
  
  int s = 0;
  for (int j = i; j < n; j++) {
    s += A[j];
    x = min(x, 10*((s+5)/10) + f(j+1, k+1));
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> d;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= d; j++) {
      dp[i][j] = -1;
    }
  }

  cout << f(0, 0) << endl;
}

