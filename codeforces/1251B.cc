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
    int o = 0;
    vector<int> A(2, 0);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      o += sz(s) % 2;
      for (auto& c : s) A[c == '0']++;
    }

    if (o % 2 == 0) {
      if (o > 0) {
        if (A[0] % 2 == A[1] % 2) {
          cout << n << endl;
        } else {
          cout << n-1 << endl;
        }
      } else {
        if (A[0] % 2 == 0 and A[1] % 2 == 0) {
          cout << n << endl;
        } else {
          cout << n-1 << endl;
        }
      }
    } else {
      if (A[0] % 2 != A[1] % 2) {
        cout << n << endl;
      } else {
        cout << n-1 << endl;
      }
    }
  }
}

