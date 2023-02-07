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

int n, k;
vector<int> A;
int dp[101010][3], v[101010][3];

int f(int i, int s) {
  if (i == n or s == 2) return 0;

  int& x = dp[i][s];
  if (v[i][s]) return x;
  v[i][s] = 1;

  if (s == 0) {
    x = max(f(i+1, s+1) + A[i] - k, f(i+1, s));
  } else {
    x = max(f(i+1, s) + A[i] - k, f(i+1, s+1));
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  cout << f(0, 0) << endl;
}

