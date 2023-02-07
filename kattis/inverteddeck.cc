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
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a;

  int l = 0, r = 0;
  for (int i = n-1; i > 0; i--) {
    if (A[i-1] > A[i]) {
      r = i;
      while (r+1 < n and A[i] == A[r+1]) r++;
      for (l = i; l > 0; l--) {
        if (A[l-1] < A[l]) {
          break;
        }
      }
      reverse(begin(A) + l, begin(A) + r + 1);
      break;
    }
  }

  bool ans = 1;
  for (int i = 0; i+1 < n; i++) {
    if (A[i] > A[i+1]) {
      ans = 0;
      break;
    }
  }

  if (ans) {
    cout << l+1 << ' ' << r+1 << endl;
  } else {
    cout << "impossible" << endl;
  }
}
