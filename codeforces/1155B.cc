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

int n;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;

  int x = 0, y = 0;
  for (int i = 0; i < n-11; i++) {
    if (s[i] == '8') x++;
    else y++;
  }

  if ((x == y or y - x == 1) and s[n-11] == '8') {
    cout << "YES" << endl;
  } else if (x == y) {
    cout << "NO" << endl;
  } else if (x > y) {
    cout << "YES" << endl;
  } else if (x < y) {
    cout << "NO" << endl;
  }
}

