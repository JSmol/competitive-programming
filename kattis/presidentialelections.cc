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

typedef long long ll;
const ll inf = (1ll<<60);
int s, x;
int D[2020];
ll C[2020];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  for (int i = 1, c, f, u; i <= s; i++) {
    cin >> D[i] >> c >> f >> u; 
    x += D[i];
    C[i] = ((c+f+u)/2+1)-c;
    if (C[i] > u) C[i] = -1;
    else if (C[i] < 0) C[i] = 0;
  }

  vector<vector<ll>> dp(s+1, vector<ll>(x+1));
  for (int i = 0; i <= s; i++) {
    for (int v = 0; v <= x; v++) {
      dp[i][v] = inf;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= s; i++) {
    for (int v = 0; v <= x; v++) {
      if (v >= D[i] and C[i] != -1)
        dp[i][v] = min(dp[i-1][v], dp[i-1][v-D[i]] + C[i]);
      else
        dp[i][v] = dp[i-1][v];
    }
  }

  ll ans = inf;
  for (int i = x/2 + 1; i <= x; i++)
    ans = min(ans, dp[s][i]);

  if (ans == inf) {
    cout << "impossible" << endl;
  } else {
    cout << ans << endl;
  }
}

