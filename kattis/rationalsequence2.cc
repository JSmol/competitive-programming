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

int f(int p, int q) {
  if (p == 1 and q == 1) return 1;
  if (p < 1 or q < 1) return 0;

  int x = 0;

  if (x = f(p, q-p)) {
    x = 2*x;
  } else {
    x = f(p-q, q);
    x = 2*x + 1;
  }

  return x;
}

int t, x, p, q;
char slash;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> x >> p >> slash >> q;
    cout << x << ' ' << f(p, q) << endl;
  }
}

