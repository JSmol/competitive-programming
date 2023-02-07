#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

int n, q;
int xs[10101], ys[10101], rs[10101], zs[10101];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i] >> rs[i] >> zs[i];
  }
  
  cin >> q;
  for (int i = 0, a, b, c, d; i < q; i++) {
    cin >> a >> b >> c >> d;
    bool x = false;
    for (int i = 0; i < n; i++) {
      int ux = xs[i] - a;
      int uy = ys[i] - b;
      int vx = rs[i] - a;
      int vy = zs[i] - b;
      int px = xs[i] - c;
      int py = ys[i] - d;
      int qx = rs[i] - c;
      int qy = zs[i] - d;
      /*
      debug(ux);
      debug(uy);
      debug(vx);
      debug(vy);
      debug(px);
      debug(py);
      debug(qx);
      debug(qy);
      cerr << endl;

      debug(ux * vy - uy * vx);
      debug(px * qy - py * qx);
      cerr << endl;
      */
      if (ux * vy - uy * vx < 0 and px * qy - py * qx > 0) x ^= 1;
      if (ux * vy - uy * vx > 0 and px * qy - py * qx < 0) x ^= 1;
    }
    cout << (!x ? "same" : "different") << endl;
  }
}

