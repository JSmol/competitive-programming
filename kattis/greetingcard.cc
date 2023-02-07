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

int sq(int x) {
  return x * x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  set<pair<long long, long long>> S;

  /*
  for (int a = 0; a <= 2018; a++) {
    for (int b = 0; b <= 2018; b++) {
      if (sq(a) + sq(b) == sq(2018)) {
        cout << a << ' ' << b << endl;
      }
    }
  }
  */

  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    S.insert({x, y});
  }

  int ans = 0;
  for (auto& a : S) {
    if (S.count({a.fst + 2018, a.snd + 0})) ans++;
    if (S.count({a.fst + 0, a.snd + 2018})) ans++;
    if (S.count({a.fst + 0, a.snd - 2018})) ans++;
    if (S.count({a.fst - 2018, a.snd + 0})) ans++;
    if (S.count({a.fst + 1118, a.snd + 1680})) ans++;
    if (S.count({a.fst - 1118, a.snd + 1680})) ans++;
    if (S.count({a.fst + 1118, a.snd - 1680})) ans++;
    if (S.count({a.fst - 1118, a.snd - 1680})) ans++;
    if (S.count({a.fst + 1680, a.snd + 1118})) ans++;
    if (S.count({a.fst - 1680, a.snd + 1118})) ans++;
    if (S.count({a.fst + 1680, a.snd - 1118})) ans++;
    if (S.count({a.fst - 1680, a.snd - 1118})) ans++;
  }

  cout << ans/2 << endl;
}

