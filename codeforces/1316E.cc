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

typedef long long ll;
#define pc __builtin_popcount
int n, p, k;
vector<ll> A;
vector<vector<ll>> P;
vector<int> I;
ll dp[101010][1 << 7];

ll f(int i, int b) {
  if (i == n) return 0;

  ll& x = dp[i][b];
  if (x != -1) return x;

  if (i - pc(b) < k) {
    x = f(i + 1, b) + A[I[i]];
  } else {
    x = f(i + 1, b);
  }

  for (int j = 0; j < p; j++) {
    if ((b >> j) & 1) continue;
    x = max(x, f(i + 1, b | (1 << j)) + P[I[i]][j]);
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> p >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  P.assign(n, vector<ll>(p));
  for (auto& p : P) for (auto& x : p) cin >> x;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1<<p); j++) {
      dp[i][j] = -1;
    }
  }

  I.assign(n, 0);
  iota(all(I), 0);
  sort(rall(I), [&] (int i, int j) { return A[i] < A[j]; });
  cout << f(0, 0) << endl;
}

