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
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<ll> A(3);
    cin >> A[0] >> A[1] >> A[2];

    ll ans = 1ll << 50;
    vector<ll> X(3);
    for (X[0] = -1; X[0] <= 1; X[0]++) {
      for (X[1] = -1; X[1] <= 1; X[1]++) {
        for (X[2] = -1; X[2] <= 1; X[2]++) {
          ll s = 0;
          for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 3; j++) {
              s += abs((A[i] + X[i]) - (A[j] + X[j]));
            }
          }

          ans = min(ans, s);
        }
      }
    }

    cout << ans << endl;

  }
}

