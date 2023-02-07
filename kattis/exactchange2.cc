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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

const int inf = (1<<30);
int t, n, k;
int A[101];
int dp[101][1010101];

int f(int i, int s) {
  if (s == 0) return 0;
  if (i == n or s < 0) return inf;

  int& x = dp[i][s];
  if (x != -1) return x;

  x = min(f(i+1, s), f(i+1, s-A[i]) + 1);

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    for (int i = 0; i < 101; i++)
      for (int j = 0; j < 1010101; j++)
        dp[i][j] = -1;

    cin >> k >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    while (f(0, k) >= inf) k++;
    cout << k << ' ' << f(0, k) << endl;
  }
}

