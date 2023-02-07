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
const ll mod = 1e9 + 7;
int g[1111][1111];
int A[1111], B[1111];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    cin >> A[i];
    for (int j = 0; j < A[i]; j++) {
      g[i][j] = 1;
    }
  }

  for (int i = 0; i < w; i++) {
    cin >> B[i];
    for (int j = 0; j < B[i]; j++) {
      g[j][i] = 1;
    }
  }

  bool flag = false;
  for (int i = 0; i < h; i++) {
    if (g[i][A[i]] == 1) flag = 1;
    else g[i][A[i]] = -1;
  }

  for (int i = 0; i < w; i++) {
    if (g[B[i]][i] == 1) flag = 1;
    else g[B[i]][i] = -1;
  }
  
  ll ans = 0;
  if (!flag) {
    ans = 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (g[i][j] == 0) ans = (ans * 2ll) % mod;
      }
    }
  }

  cout << ans << endl;
}

