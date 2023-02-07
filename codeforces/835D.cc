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

int dp[5050][5050];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = sz(s);

  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      dp[i][j] = 1;

  // dp[l][r] = largest k for which s[l..r] is a k-palidrome.
  rep (d, 1, n) {
    for (int l = 0; l + d < n; l++) {
      if (s[l] != s[l+d] or dp[l+1][l+d-1] == 0) dp[l][l+d] = 0;
      else dp[l][l+d] = dp[l][(l+(d+1)/2)-1] + 1;
    }
  }

  vector<int> c(n+1);
  rep (i, 0, n) {
    rep (j, i, n) {
      c[dp[i][j]]++;
    }
  }

  vector<int> ans(n);
  rep (i, 1, n+1) {
    rep (j, i, n+1) {
      ans[i-1] += c[j];
    }
  }

  trav (a, ans) cout << a << ' ';
  cout << endl;
}

