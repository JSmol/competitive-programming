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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    vector<int> B(n);
    for (auto& x : B) cin >> x;

    bool ans = 1;
    for (int i = 0, p = 0, d = 0; i < n; i++) {
      if (p == 0 and A[i] != B[i]) {
        p = 1;
        d = B[i] - A[i];
        if (d < 0) {
          ans = 0;
          break;
        }
      }

      if (p == 1 and A[i] != B[i]) {
        if (B[i] - A[i] != d) {
          ans = 0;
          break;
        }
      }

      if (p == 1 and A[i] == B[i]) {
        p = 2;
      }

      if (p == 2 and A[i] != B[i]) {
        ans = 0;
        break;
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}

