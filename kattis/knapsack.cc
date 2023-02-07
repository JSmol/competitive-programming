#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
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

int n, k; double c;
int dp[2002][2002], W[2002], V[2002];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (cin >> c >> n) {
    k = floor(c);
    for (int i = 1; i <= n; i++) cin >> V[i] >> W[i];

    for (int i = 1; i <= n; i++) {
      for (int s = 0; s <= k; s++) {
        if (W[i] <= s) {
          dp[i][s] = max(dp[i-1][s], dp[i-1][s-W[i]] + V[i]);
        } else {
          dp[i][s] = dp[i-1][s];
        }
      }
    }
    
    vector<int> ans;
    for (int i = n, s = dp[n][k]; i > 0 and s > 0; i--) {
      if (W[i] <= k and dp[i-1][k-W[i]] + V[i] == dp[i][k])
        ans.push_back(i-1), s -= V[i], k -= W[i];
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    for (auto& a : ans) cout << a << ' ';
    cout << endl;
  }
}

