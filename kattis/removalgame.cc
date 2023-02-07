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

int n;
vector<int> A;
int dp[101][101];

// A[i] and A[i+l-1] are last.
int f(int i, int l) {
  int& x = dp[i][l];
  if (x != -1) return x;
  if (l <= 2) return x = 0;

  x = 1 << 30;
  for (int j = 2; j < l; j++) {
    x = min(x, f(i, j) + f((i+j-1) % n, (l-j+1) % n) + __gcd(A[i], A[(i+l-1) % n]));
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (cin >> n and n != 0) {
    for (int i = 0; i <= n; i++) fill(dp[i], dp[i]+n+1, -1);

    A.assign(n, 0);
    for (auto& a : A) cin >> a;

    int ans = 1 << 30;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        ans = min(ans, f(i, j-i+1) + f(j, n-j+i+1) + __gcd(A[i], A[j]));
      }
    }

    cout << ans << endl;
  }
}

