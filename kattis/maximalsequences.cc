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
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  int q; cin >> q;
  vector<pair<int, vector<int>>> Q(q);
  for (int i = 0; i < q; i++) {
    cin >> Q[i].fst; Q[i].fst--;
    int m; cin >> m;
    Q[i].snd.assign(m, 0);
    for (auto& x : Q[i].snd) cin >> x;
  }

  vector<int> I(q); iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return Q[i].fst > Q[j].fst; });

  set<int> S;
  map<int, int> X;
  vector<int> ans(q);
  for (int i = n-1, j = 0; i >= 0; i--) {
    if (X.count(a[i])) S.erase(X[a[i]]);
    X[a[i]] = i;
    S.insert(i);

    while (j < q and Q[I[j]].fst == i) {

      /*
      debug(Q[I[j]]);
      debug(X);
      debug(S);
      debug(i);
      */

      auto [idx, s] = Q[I[j]];
      for (int i = 0; i < sz(s); i++) {
        if (X.count(s[i])) S.erase(X[s[i]]);
      }

      if (!S.empty())
        ans[I[j]] = *begin(S) - idx;
      else
        ans[I[j]] = n - idx;

      for (int i = 0; i < sz(s); i++) {
        if (X.count(s[i])) S.insert(X[s[i]]);
      }

      j += 1;
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}

