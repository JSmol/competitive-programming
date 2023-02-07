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

int n, k;
vector<int> A;
bool f(int x) {
  int cur = 0, i = 0;
  set<int> start;
  while (cur != x and i < n) {
    if ((cur | (x & A[i])) != cur) {
      start.insert(i);
    }
    
    cur |= (x & A[i]);
    i++;
  }

  cur = 0, i = n-1;
  while (cur != x and i >= 0) {
    if ((cur | (x & A[i])) != cur) {
      start.insert(i);
    }
    
    cur |= (x & A[i]);
    i--;
  }

  assert(sz(start) <= 60);

  if (cur == x) {
    for (auto& s : start) {
      int m = 0, cmps = 0;
      for (int i = 0; i < n; i++) {
        m |= (x & A[(s+i) % n]);
        if (m == x) cmps++, m = 0;
      }

      if (cmps >= k) return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  int ans = 0;
  for (int b = 30; b >= 0; b--) {
    if (f(ans | (1 << b))) ans |= (1 << b);
  }

  cout << ans << endl;
}
