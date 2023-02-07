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

const int inf = 2*1e9;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, p, q, s; cin >> n >> p >> q >> s;
  vector<int> P(p), Q(q);
  for (auto& x : P) cin >> x;
  sort(rall(P));
  for (auto& x : Q) cin >> x; 
  sort(all(Q));

  auto f = [&] (int x) {
    int z = 0;
    multiset<int, greater<>> S(all(Q));
    for (int i = 0; i < p; i++) {
      int m = s - P[i];
      int ub1 = (S.lower_bound(m) == S.end() ? inf : *S.lower_bound(m));
      int ub2 = (S.lower_bound(P[i] + x) == S.end() ? inf : *S.lower_bound(P[i] + x));
      int next = min(ub1, ub2);
      if (P[i] - x <= next and next <= P[i] + x and next + P[i] <= s) {
        S.erase(S.find(next)); z++;
      }
    }

    return z >= n;
  };

  int l = 0, h = 1e9 + 1; 
  while (h - l > 1) {
    int m = (h + l) / 2;
    if (f(m)) h = m;
    else l = m+1;
  }

  while (f(h)) h--;
  if (h > 1e9) cout << -1 << endl;
  else cout << h+1 << endl;
}

