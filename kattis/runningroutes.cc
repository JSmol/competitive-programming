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

int n;
int A[505][505];
int dp[505][505];

int f(int s, int l) {
  assert(l >= 0);
  int& x = dp[s][l];
  if (x != -1) return x;
  if (l <= 1) return x = 0;

  x = f((s+1) % n, l-1);
  for (int i = 1; i < l; i++) {
    if (A[s % n][(s+i) % n]) {
      x = max(x, f((s+1) % n, i-1) + f((s+i+1) % n, l - i - 1) + 1);
    }
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> A[i][j];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = -1;

  cout << f(0, n) << endl;
}

