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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;
    reverse(all(B));

    vector<int> C(n+1), D(n+1);
    for (int i = 1; i <= n; i++) {
      C[i] = C[i-1] + (A[i-1] == 1) - (A[i-1] == 2);
      D[i] = D[i-1] + (B[i-1] == 1) - (B[i-1] == 2);
    }

    map<int, int> M;
    for (int i = 0; i <= n; i++) {
      M[D[i]] = i;
    }

    int ans = 2*n;
    for (int i = 0; i <= n; i++) {
      if (M.count(-C[i])) {
        ans = min(ans, (n-i) + (n-M[-C[i]]));
      }
    }

    cout << ans << endl;
  }
}

