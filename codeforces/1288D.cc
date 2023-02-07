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

int a = -1, b = -1;
int n, m;
vector<vector<int>> A;

void ans(int x) {
  vector<int> X(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] >= x) X[i] |= (1 << j);
    }
  }

  map<int, int> S;
  for (int i = 0; i < n; i++)
    S[X[i]] = i;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      if ((X[i] | j) == ((1 << m) - 1) and S.count(j)) {
        a = i;
        b = S[j];
        return;
      }
    }
  }

  assert(0);
}

bool g(vector<int>& X) {
  unordered_set<int> S(all(X));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      if ((X[i] | j) == ((1 << m) - 1) and S.count(j)) return 1;
    }
  }

  return 0;
}

bool f(int x) {
  vector<int> X(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] >= x) X[i] |= (1 << j);
    }
  }

  return g(X);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, vector<int>(m));
  for (auto& a : A) for (auto& x : a) cin >> x;

  int h = 1e9, l = 0;
  while (h - l > 2) {
    int m = (h + l) / 2;
    if (f(m)) l = m;
    else h = m;
  }

  while (f(l)) l++;
  ans(l-1);
  assert(a >= 0 and b >= 0);
  cout << a+1 << ' ' << b+1 << endl;
}

