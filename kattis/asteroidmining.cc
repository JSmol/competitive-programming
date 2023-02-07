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

typedef double ld;
typedef priority_queue<ld> pq;
const int thresh = 210000;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int m, n, e; cin >> m >> n >> e;
  vector<pq> A(m);
  vector<ld> S(m);
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      ld x; cin >> x;
      A[i].push(x);
      S[i] += x;
    }
  }

  auto combine = [&] (pq x, ld fx, pq y, ld fy) {
    pq res;
    while (sz(res) < thresh) {
      if (x.empty() and y.empty()) break;
      if (x.empty()) {
        res.push(fy * y.top());
        y.pop();
      } else
      if (y.empty()) {
        res.push(fx * x.top());
        x.pop();
      } else {
        if (x.top() < y.top()) {
          res.push(fy * y.top());
          y.pop();
        } else {
          res.push(fx * x.top());
          x.pop();
        }
      }
    }
    return res;
  };

  for (int _ = 0; _ < e; _++) {
    string s; cin >> s;
    if (s == "mine") {
      int i, g; cin >> i >> g;
      while (g--) {
        S[i] -= A[i].top();
        A[i].pop();
      }
    } else {
      int i, j; ld fi, fj;
      cin >> i >> fi >> j >> fj;
      S[n] = S[i] * fi + S[j] * fj;
      A[n] = combine(A[i], fi, A[j], fj);
      n++;
    }
  }

  for (int i = 0; i < m; i++) {
    if (A[i].empty()) {
      cout << 0 << ' ' << 0 << endl;
    } else {
      cout << fixed << setprecision(12) << S[i] << ' ' << A[i].top() << endl;
    }
  }
}

