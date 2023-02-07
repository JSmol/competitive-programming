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

typedef long long ll;
vector<int>primes;
int factor(int n) {
  int res = 0;
  int m = n;
  for (auto& i : primes) {
    while (m % i == 0) {
      m /= i;
      res += i;
    }
  }

  if (m > 1) res += m;
  return res;
}

bool f(ll m) {
  for (auto& i : primes) {
    if (i < m and m % i == 0) {
      return false;
    }
  }

  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ll N = 1<<15;
  vector<int> p(N, 1);
  for (ll i = 2; i < N; i++) {
    if (p[i]) {
      primes.push_back(i);
      for (ll j = i*i; j < N; j += i) {
        p[j] = 0;
      }
    }
  }

  int n;
  vector<pair<int, int>> answers;
  while (cin >> n and n != 4) {
    int ans = 1;
    while (1) {
      int nxt = factor(n);
      if (nxt == n) break;
      n = nxt;
      ans++;
    }

    answers.push_back({n, ans});
  }

  for (auto& [n, ans] : answers) {
    cout << n << ' ' << ans << '\n';
  }
}

