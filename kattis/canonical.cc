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

int n, A[101], dp[101][2020202];

int g(int k) {
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (k >= A[i]) {
      c += k / A[i];
      k %= A[i];
    }
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  reverse(A+1, A+1+n);

  dp[0][0] = 0;
  for (int s = 1; s <= A[1] + A[2]; s++) dp[0][s] = (1 << 30);
  for (int i = 1; i <= n; i++) {
    for (int s = 1; s <= A[1] + A[2]; s++) {
      if (s >= A[i]) dp[i][s] = min(dp[i][s-A[i]] + 1, dp[i-1][s]);
      else dp[i][s] = dp[i-1][s];
    }
  }

  for (int s = 1; s <= A[1] + A[2]; s++) {
    if (g(s) != dp[n][s]) {
      cout << "non-canonical" << endl;
      return 0;
    }
  }
  cout << "canonical" << endl;
}

