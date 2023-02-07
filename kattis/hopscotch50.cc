#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y) 
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
typedef long double ld;
typedef long long ll;

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
  int n, k; cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n));
  for (auto& a : A) for (auto& x : a) cin >> x;

  int ans = -1;
  set<pair<int, int>> S;
  priority_queue<pair<int, pair<int, int>>> Q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
      if (A[i][j] == 1) Q.push({0, {i, j}});
  while (!Q.empty()) {
    auto [d, x] = Q.top(); Q.pop();
    int& v = A[x.fst][x.snd];
    if (S.count(x)) continue;
    S.insert(x);
    if (v == k) {
      ans = -d;
      break;
    } else {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (A[i][j] == v+1)
            Q.push({d - (abs(x.fst - i) + abs(x.snd - j)), {i, j}});
    }
  }

  cout << ans << endl;
} 

