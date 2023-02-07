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
  int n, a, b, x, y;
  cin >> n >> a >> x >> b >> y;

  bool ans = false;
  if (a == b) {
    ans = true;
  } else {
    a %= n; b %= n;
    x %= n; y %= n;
    while (a != x and b != y) {
      if (a != x) a = (a+1) % n;
      if (b != y) b = ((b-1)+n) % n;
      if (a == b) {
        ans = true;
        break;
      }
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
}

