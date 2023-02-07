#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int n;
vector<int> A;
int dp[202020][3];
int f(int i, int s) {
  int& x = dp[i][s];
  if (x != -1) return x;
  if (i == n) return x = 0;

  x = 1 << 30;
  if (s == 0) {
    if (A[i] == 0) x = min({f(i+1, 0), f(i+1, 1), f(i+1, 2)});
    if (A[i] == 1) x = min({1 + f(i+1, 0), f(i+1, 1), 1 + f(i+1, 2)});
    if (A[i] == 2) x = min({1 + f(i+1, 0), 1 + f(i+1, 1), f(i+1, 2)});
  }

  if (s == 1) {
    if (A[i] == 0) x = min({1 + f(i+1, 1), 1 + f(i+1, 2)});
    if (A[i] == 1) x = min({f(i+1, 1), 1 + f(i+1, 2)});
    if (A[i] == 2) x = min({1 + f(i+1, 1), f(i+1, 2)});
  }

  if (s == 2) {
    if (A[i] == 0) x = 1 + f(i+1, 2);
    if (A[i] == 1) x = 1 + f(i+1, 2);
    if (A[i] == 2) x = f(i+1, 2);
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k1,k2,k3;
  cin >> k1 >> k2 >> k3;
  n = k1+k2+k3;
  A.assign(n, 0);
  for (int i = 0,x; i < k1; i++) cin >> x, A[x-1] = 0;
  for (int i = 0,x; i < k2; i++) cin >> x, A[x-1] = 1;
  for (int i = 0,x; i < k3; i++) cin >> x, A[x-1] = 2;

  for (int i = 0; i <= n; i++) {
    dp[i][0] = dp[i][1] = dp[i][2] = -1;
  }

  cout << f(0, 0) << endl;
}

