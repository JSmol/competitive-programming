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

bool check(int n) {
  set<char> S;
  string s = to_string(n);
  for (auto& c : s) {
    S.insert(c);
  }
  return S.size() == s.length();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, r;
  cin >> l >> r;
  int ans = -1;
  for (int i = l; i <= r; i++) {
    if (check(i)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}

