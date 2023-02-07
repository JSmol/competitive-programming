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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0, a = 0, b = 0; i < n; i++) {
    a += (s[i] == 'a');
    b += (s[i] == 'b');
    if (i % 2) {
      if (a != b) {
        ans++;
        if (a < b) {
          s[i] = 'a';
          a++;
          b--;
        } else {
          s[i] = 'b';
          a--;
          b++;
        }
      }
    }
  }
  cout << ans << endl;
  cout << s << endl;
}

