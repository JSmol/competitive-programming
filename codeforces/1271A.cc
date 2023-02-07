#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n, m;
  cin >> n >> m;


  // a + d = n
  // b + c + d = m
  int cost = 0;
  if (n >= m) {
    cost = min(a, d) * n;
    d -= min(a, d);
    cost += min({b, c, d}) * m;
  } else {
    cost = min({b, c, d}) * m;
    d -= min({b, c, d});
    cost += min(a, d) * n;
  }
  cout << cost << endl;
}

