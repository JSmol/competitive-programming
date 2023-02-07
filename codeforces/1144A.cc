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

int t;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (cin >> s) {
    int n = s.size();
    sort(all(s));
    bool d = true;
    for (int i = 1; i < n; i++) {
      if (s[i-1] != s[i]-1)
        d = false;
    }
    if (d) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

