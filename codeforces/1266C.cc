#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

typedef long long ll;
ll a[505][505];
void f(int n, int m) {
  vector<ll> X(n), Y(m);

  Y[0] = 1; X[0] = 2;
  int i = 1, j = 1, s = 3;
  while (s <= n+m) {
    if (s % 2 == 0 and j < m) Y[j] = s, j++;
    else assert(i<n), X[i] = s, i++;
    s++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = (X[i] * Y[j]) / __gcd(X[i], Y[j]);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;

  bool p = 0;
  if (n < m) swap(n, m), p = 1;

  if (n == 1 and m == 1) {
    cout << 0 << endl;
    return 0;
  }

  f(n, m);
  if (p) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[j][i] << ' ';
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << ' ';
      }
      cout << endl;
    }
  }
}

