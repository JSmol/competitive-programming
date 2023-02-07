#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
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
double time() { return double(clock()) / CLOCKS_PER_SEC; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int C = 1; C <= T; C++) {
    int n; cin >> n;
    vector<int> a(n);
    iota(all(a), 1);

    int moves = 0;

    int i = n-2;
    int sq = ceil(sqrt(a[n-1]));
    vector<pair<int, int>> ans;
    while (i > 0) {
      if ((a[n-1] + a[i-1] - 1) / a[i-1] > sq) {
        a[n-1] = (a[n-1] + a[i] - 1) / a[i];
        ans.push_back({n, i+1});
        sq = ceil(sqrt(a[n-1]));
      } else {
        a[i] = (a[i] + a[n-1] - 1) / a[n-1];
        ans.push_back({i+1, n});
        i -= 1;
      }
      moves += 1;
      // debug(a);
    }

    // debug(moves);
    // debug(mp(count(all(a), 1), count(all(a), 2)));
    cout << sz(ans) << endl;
    for (auto [a, b] : ans) cout << a << ' ' << b << endl;
  }
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 1 2 3 4 1 1 1 1 1 1  1  1  1  1  1  16 (11)
// 1 2 3 4 1 1 1 1 1 1  1  1  1  1  1  4  (12)
// 1 2 1 4 1 1 1 1 1 1  1  1  1  1  1  4  (13) 1 2 and 8 4s?
