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

int maxa = 3;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  map<int, int> s, m;
  vector<pair<char, int>> A(n);
  for (int i = 0; i < n; i++) { 
    cin >> A[i].fst >> A[i].snd; A[i].snd--;
    s[A[i].snd] += (A[i].fst == 's' ? 1 : -1);
    m[A[i].snd] = min(m[A[i].snd], s[A[i].snd]);
  }

  int c = 0;
  for (auto& x : m) if (s[x.fst] == 0 and x.snd == 0) c++;

  int best = c, ans = 0;
  for (int i = 0; i < n; i++) {
    auto [x, j] = A[i];
    if (s[j] != 0) continue;

    if (m[j] < 0) {
      m[j] += (x == 's' ? -1 : 1);
      if (m[j] == 0) c++;
    } else {
      m[j] += (x == 's' ? -1 : 1);
      assert(m[j] < 0);
      c--;
    }

    if (best < c) best = c, ans = i+1;
  }

  cout << (ans % n) +1 << ' ' << best << endl;
}

