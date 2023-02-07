#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define all(X) begin(X), end(X)
#define sz(X) (int) X.size()

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    string t;
    for (int i = 0; i < k; i++) {
      if (i == k-1) {
        int l = n - 2*(k-1);
        for (int j = 0; 2*j < l; j++) t += '(';
        for (int j = 0; 2*j < l; j++) t += ')';
      } else {
        t += "()";
      }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        for (int j = i+1; j < n; j++) {
          if (s[j] != s[i]) {
            ans.push_back({i+1, j+1});
            reverse(begin(s)+i, begin(s)+j+1);
            break;
          }
        }
      }
    }

    assert(sz(ans) <= n);
    cout << sz(ans) << endl;
    for (auto& a : ans) {
      cout << a.fst << ' ' << a.snd << endl;
    }
  }
}
1
1
1

