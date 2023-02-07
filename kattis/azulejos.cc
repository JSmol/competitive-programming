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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> b(n), f(n);
  for (int i = 0; i < n; i++) cin >> b[i].fst;
  for (int i = 0; i < n; i++) cin >> b[i].snd;
  for (int i = 0; i < n; i++) cin >> f[i].fst;
  for (int i = 0; i < n; i++) cin >> f[i].snd;

  vector<int> I(n); iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return b[i] < b[j]; });
  vector<int> J(n); iota(all(J), 0);
  sort(all(J), [&] (int i, int j) { return f[i] < f[j]; });

  vector<int> as1, as2;
  set<pair<int, int>> S, T;
  int i = 0, j = 0, k = 0, l = 0;
  while (sz(as1) < n) {
    while (k < n and b[I[i]].fst == b[I[k]].fst) S.insert({b[I[k]].snd, I[k]}), k++;
    while (l < n and f[J[j]].fst == f[J[l]].fst) T.insert({-f[J[l]].snd, J[l]}), l++;
    if (S.empty() and T.empty()) break;

    if (sz(S) <= sz(T)) {
      for (auto& s : S) {
        auto bound = T.upper_bound({-s.fst, 1<<30});
        if (bound == end(T) or bound->fst == -s.fst) {
          cout << "impossible" << endl;
          return 0;
        } else {
          as1.push_back(s.snd);
          as2.push_back(bound->snd);
          T.erase(bound);
          j++; i++;
        }
      }

      S.clear();
    } else {
      for (auto& t : T) {
        auto bound = S.upper_bound({-t.fst, 1<<30});
        if (bound == end(S) or bound->fst == -t.fst) {
          cout << "impossible" << endl;
          return 0;
        } else {
          as2.push_back(t.snd);
          as1.push_back(bound->snd);
          S.erase(bound);
          j++; i++;
        }
      }

      T.clear();
    }
  }

  for (auto& a : as1) cout << a+1 << ' ';
  cout << endl;
  for (auto& a : as2) cout << a+1 << ' ';
  cout << endl;
}

