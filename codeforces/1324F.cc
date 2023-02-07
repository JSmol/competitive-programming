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

int n;
vector<vector<int>> A;
vector<int> X;

const int N = 200000;
int dp[N];

int f(int v, int p) {
  int& x = dp[v] = X[v];
  for (auto& a : A[v]) {
    if (a == p) continue;
    x += max(0, f(a, v));
  }

  return x;
}

int ans[N];
void g(int v, int p) {
  ans[v] = dp[v];
  for (auto& a : A[v]) {
    if (a == p) continue;
    dp[v] -= max(0, dp[a]);
    dp[a] += max(0, dp[v]);
    g(a, v);
    dp[a] -= max(0, dp[v]);
    dp[v] += max(0, dp[a]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  X.assign(n, 0);
  for (auto& x : X) cin >> x, x = (x ? 1 : -1);
  A.assign(n, {});
  for (int i = 0, a, b; i < n-1; i++) {
    cin >> a >> b; a--; b--;
    A[a].push_back(b);
    A[b].push_back(a);
  }
  
  f(0, -1); g(0, -1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
  }
}

