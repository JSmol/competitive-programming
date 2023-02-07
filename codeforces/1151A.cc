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

const string t = "ACTG";
int n;
string s;

int d(char a, char b) {
  int x = a - 'A', y = b - 'A';
  if (x > y) return min(x - y, y - x + 26);
  else return min(y - x, x - y + 26);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s;

  int ans = 1<<30;
  for (int i = 0; i < n-3; i++) {
    int x = 0;
    for (int j = 0; j < 4; j++) {
      x += d(t[j], s[i+j]);
    }
    ans = min(ans, x);
  }
  cout << ans << endl;
}

