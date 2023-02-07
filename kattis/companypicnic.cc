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

#define double long double
int n;
vector<double> S;
vector<vector<int>> A;
pair<int, double> dp[1010][2];

pair<int, double> f(int v, int p) {
  pair<int, double>& x = dp[v][p];
  if (x.fst != -1) return x;

  x = {0, 0};
  for (auto& a : A[v]) {
    x.fst += f(a, 0).fst;
    x.snd += f(a, 0).snd;
  }

  if (!p) {
    for (int i = 0; i < sz(A[v]); i++) {
      int c = 1 + f(A[v][i], 1).fst;
      double t = min(S[v], S[A[v][i]]) + f(A[v][i], 1).snd;
      for (int j = 0; j < sz(A[v]); j++) {
        if (i == j) continue;
        c += f(A[v][j], 0).fst;
        t += f(A[v][j], 0).snd;
      }

      if (x.fst < c) x = {c, t};
      if (x.fst == c and x.snd < t) x = {c, t};
    } 
  }
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int root = -1;
  A.assign(n, {});
  S.assign(n, {});
  map<string, int> M;
  for (int i = 0, id = 0; i < n; i++) {
    string s, t; double x;
    cin >> s >> x >> t;
    if (!M.count(s)) M[s] = id++;
    S[M[s]] = x;

    if (t == "CEO") root = M[s];
    else {
      if (!M.count(t)) M[t] = id++;
      A[M[t]].push_back(M[s]);
    }
  }

  for (int i = 0; i < n; i++)
    dp[i][0] = dp[i][1] = {-1, -1};

  auto [c, t] = f(root, 0);
  cout << fixed << setprecision(9) << c << ' ' << t / c << endl;
}

