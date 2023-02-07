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
  vector<int> A(9);
  int t;
  cin >> t;
  while (t--) {
    int z;
    cin >> z;
    for (int i = 0; i < 9; i++) {
      cin >> A[i];
    }

    string ans;
    int m = *min_element(all(A));
    if (z < m) {
      ans += '1';
      for (int i = 0; i <= z; i++) {
        ans += '0';
      }
    } else {
      int x = 0;
      for (int i = 0; i < 9; i++) {
        if (A[i] == m) {
          x = i+1;
          break;
        }
      }

      for (int i = 0; i <= m; i++) {
        ans += (char) x + '0';
      }
    }

    cout << ans << endl;
  }
}

