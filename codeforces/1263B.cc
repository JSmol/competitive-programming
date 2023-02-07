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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, int> M;
    vector<string> A(n);
    for (auto& a : A) cin >> a, M[a]++;

    int ans = 0;
    for (auto& a : A) {
      if (M[a] > 1) {
        for (int j = 0; j < 4; j++) {
          for (int i = 0; i < 10; i++) {
            string s = a;
            s[j] = i + '0';
            if (M[s] == 0) {
              M[a]--;
              M[s]++;
              a = s;
              ans++;
              goto next;
            }
          }
        }
      }
    next:;
    }
    cout << ans << endl;
    for (auto& a : A) cout << a << endl;
  }
}

