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

int n, f[11];
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= 10; i++) cin >> f[i];

  for (int i = 0, p = 0; i < n; i++) {
    if ((!p and f[s[i]-'0'] > s[i]-'0') or (p and f[s[i]-'0'] >= s[i]-'0')) p = 1, s[i] = f[s[i]-'0']+'0';
    else if (p) break;
  }
  cout << s << endl;
}

