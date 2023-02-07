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

typedef long long ll;
ll dp[25][145];
ll X[25];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  X[0] = 1;
  for (int i = 1; i <= 24; i++)
    X[i] = X[i-1]*6;

  dp[0][0] = 1;
  for (int n = 0; n <= 24; n++)
    for (int s = 0; s <= 6*24; s++)
      for (int i = 1; i <= 6; i++)
        if (s-i >= 0)
          dp[n][s] += (n ? dp[n-1][s-i] : 0);

  int k, t, s;
  cin >> k >> t;
  vector<int> A(7, 0);
  for (int i = 0, x; i < k; i++) cin >> x, A[x]++, s += x;

  ll x = (s == t); ll y = 0;
  for (int i1 = 0; i1 <= A[1]; i1++) {
    for (int i2 = 0; i2 <= A[2]; i2++) {
      for (int i3 = 0; i3 <= A[3]; i3++) {
        for (int i4 = 0; i4 <= A[4]; i4++) {
          for (int i5 = 0; i5 <= A[5]; i5++) {
            for (int i6 = 0; i6 <= A[6]; i6++) {
              ll g = t - (s - (i1 + i2*2 + i3*3 + i4*4 + i5*5 + i6*6));
              ll n = i1 + i2 + i3 + i4 + i5 + i6;
              if (g <= 0 or g > t) continue;

              ll m = min(n, y);
              if (x * (X[n] / X[m]) < dp[n][g] * (X[y] / X[m])) {
                x = dp[n][g];
                y = n;
              }

              if (x * (X[n] / X[m]) == dp[n][g] * (X[y] / X[m]) and n < y) {
                x = dp[n][g];
                y = n;
              }
            }
          }
        }
      }
    }
  }

  cout << y << endl;
}
