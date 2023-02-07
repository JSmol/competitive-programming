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
  int n;
  string s;
  cin >> n >> s;

  int b = 0, w = 0;
  for (auto& c : s) {
    b += c == 'B';
    w += c == 'W';
  }

  if (b % 2 == 0) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B' and s[i+1] == 'B') {
        s[i] = s[i+1] = 'W';
        ans.push_back(i+1);
      } else 
      if (s[i] == 'B') {
        swap(s[i], s[i+1]);
        ans.push_back(i+1);
      }
    }

    cout << sz(ans) << endl;
    for (auto& a : ans) cout << a << ' ';
    cout << endl;

  } else 
  if (w % 2 == 0) {
    vector<int> ans;
    for (int i = 0; i+1 < n; i++) {
      if (s[i] == 'W' and s[i+1] == 'W') {
        s[i] = s[i+1] = 'B';
        ans.push_back(i+1);
      } else 
      if (s[i] == 'W') {
        swap(s[i], s[i+1]);
        ans.push_back(i+1);
      }
    }

    cout << sz(ans) << endl;
    for (auto& a : ans) cout << a << ' ';
    cout << endl;

  } else {
    cout << -1 << endl;
  }
}

