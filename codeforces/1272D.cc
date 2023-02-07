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
  int n; cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a;

  int ans = 0;
  vector<int> l(n, 1), r(n, 1);
  for (int i = 0; i < n; i++) {
    if (i and A[i-1] < A[i]) l[i] = l[i-1] + 1;
    if (n-i < n and A[n-i-1] < A[n-i]) r[n-i-1] = r[n-i] + 1;
    ans = max({ans, l[i], r[i]});
  }

  for (int m = 1; m+1 < n; m++) {
    if (A[m-1] < A[m+1]) {
      ans = max(ans, l[m-1] + r[m+1]);
    }
  }

  cout << ans << endl;
}

