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

int n, b, t, j;
bool ans;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  while (n--) {
    cin >> s;
    b = t = j = 0;
    ans = 1;
    for (auto& c : s) {
      if (c == '.') continue;

      if (c == '$') b++;
      if (c == '|') t++;
      if (c == '*') j++;
      if (c == 'b') b--;
      if (c == 't') t--;
      if (c == 'j') j--;

      if (b < 0 or t < 0 or j < 0) ans = false;
    }
    if (b > 0  or t > 0 or j > 0) ans = false;
    cout << (ans ? "YES" : "NO") << endl;
  }
}

