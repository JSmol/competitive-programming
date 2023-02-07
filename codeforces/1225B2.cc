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

template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

int A[202020];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) cin >> A[i];

    int x = 0;
    map<int, int> X;
    for (int i = 0; i < d; i++) {
      if (X[A[i]] == 0) x++;
      X[A[i]]++;
    }

    int ans = x;
    for (int i = d; i < n; i++) {
      if (X[A[i]] == 0) x++;
      X[A[i]]++;
      if (X[A[i-d]] == 1) x--;
      X[A[i-d]]--;
      ans = min(ans, x);
    }

    cout << ans << endl;
  }
}

