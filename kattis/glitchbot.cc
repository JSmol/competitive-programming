#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

int x, y, n; 
vector<string> A;
vector<pair<int, int>> dirs = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

bool f() {
  int cx = 0, cy = 0, dir = 0;
  for (int i = 0; i < n; i++) {

    if (A[i] == "Forward") {
      cx += dirs[dir].fst;
      cy += dirs[dir].snd;
    }

    if (A[i] == "Right") {
      dir += 1;
      dir %= 4;
    }

    if (A[i] == "Left") {
      dir += 3;
      dir %= 4;
    }
  }

  return (cx == x and cy == y);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> x >> y >> n;
  A.assign(n, {});
  for (auto& a : A) cin >> a;
  for (int i = 0; i < n; i++) {
    string t = A[i];
    for (string s : {"Forward", "Right", "Left"}) {
      A[i] = s;
      if (f()) {
        cout << i+1 << ' ' << s << endl;
        return 0;
      }
    }

    A[i] = t;
  }
}

