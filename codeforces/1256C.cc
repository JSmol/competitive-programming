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

int dp[1010][1010];
int n, m, d;
vector<int> A, ans;
int f(int i, int j) {
  if (i == n and j > m) return 1;
  if (i >= n or j > m) return 0;

  if (i != -1) {
    int& z = dp[i][j];
    if (z != -1) return 0;
    z = 0;
  }

  for (int jump = 1; jump <= d; jump++) {
    if (j < m) {
      if (f(i + jump + (A[j]-1), j+1)) {
        for (int x = i + jump; x <= i + jump + (A[j]-1); x++) ans[x] = j+1;
        return 1;
      }
    } else {
      if (i + jump == n) return 1;
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> d;
  A.assign(m, 0);
  for (auto& a : A) cin >> a;

  rep (i, 0, 1010)
    rep (j, 0, 1010)
      dp[i][j] = -1;

  ans.assign(n, 0);
  if (f(-1, 0)) {
    cout << "YES" << endl;
    for (auto& a : ans) cout << a << ' ';
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
