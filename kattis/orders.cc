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

typedef long long ll;
int n, m, k;
ll dp[30003][101], A[101];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];

  for (int s = 0; s <= 30000; s++) {
    for (int i = 1; i <= n; i++) {
      if (s == 0) dp[s][i] = 1;
      else {
        ll& a = A[i];
        if (a <= s) {
          dp[s][i] += dp[s-a][i] + dp[s][i-1];
        } else {
          dp[s][i] += dp[s][i-1];
        }
      }
    }
  }

  cin >> m;
  while (m--) {
    cin >> k;

    ll ans = dp[k][n];

    if (ans == 0) {
      cout << "Impossible" << endl;
    }

    if (ans > 1) {
      cout << "Ambiguous" << endl;
    }

    if (ans == 1) {
      vector<int> a;
      int s = k;
      int i = n;
      while (s > 0 and i > 0) {
        if (s >= A[i] and dp[s - A[i]][i] > 0) {
          a.push_back(i), s -= A[i];
        } else {
          i--;
        }
      }
      assert(s == 0);
      reverse(all(a));
      cout << a << endl;
    }
  }
}

