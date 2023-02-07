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

#define double long double
double dist(pair<double, double> x, pair<double, double> y) {
  return hypot(x.fst - y.fst, x.snd - y.snd);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t; cin >> n >> t;
  vector<pair<double, pair<double, double>>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].snd.fst >> A[i].snd.snd >> A[i].fst;
  }

  vector<pair<double, pair<double, double>>> path = {A[0]};
  for (int time = t; time < A[n-1].fst; time += t) {
    for (int i = 0; i < n; i++) {
      if (time >= A[i].fst) continue;
      assert(i != 0);
      double s = A[i].fst - A[i-1].fst;
      double g = time - A[i-1].fst;
      double dx = (A[i].snd.fst - A[i-1].snd.fst) / s;
      double dy = (A[i].snd.snd - A[i-1].snd.snd) / s;
      path.push_back({time, {A[i-1].snd.fst + dx * g, A[i-1].snd.snd + dy * g}});
      break;
    }
  }

  path.push_back(A[n-1]);

  double s1 = 0;
  for (int i = 1; i < n; i++) {
    s1 += dist(A[i].snd, A[i-1].snd);
  }

  double s2 = 0;
  for (int i = 1; i < sz(path); i++) {
    s2 += dist(path[i].snd, path[i-1].snd);
  }
  
  debug(s2);
  cout << fixed << setprecision(9) << (s1 - s2) / s1 * 100.0 << endl;
} 

