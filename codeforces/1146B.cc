#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

string t;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  int n = t.length();
  int a = 0;
  for (int i = n-1; i >= 0; i--) {
    if (t[i] == 'a') {
      a = i;
      break;
    }
  }

  string s = "";
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] != 'a') s += t[i];
    if (i == a) m = s.size();
  }
  
  if (s.size()%2 == 0 and m <= s.size()/2) {
    for (int i = 0; i < s.size()/2; i++) {
      if (s[i] != s[s.size()/2+i]) {
        cout << ":(" << endl;
        return 0;
      }
    }

    int i = 0, j = 0;
    string ans = "";
    while (j < s.size()/2 or i <= a) {
      if (j < s.size()/2 and t[i] == s[j]) j++;
      ans += t[i];
      i++;
    }
    cout << ans << endl;
    return 0;
  }
  cout << ":(" << endl;
}

