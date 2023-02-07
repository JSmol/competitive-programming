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

long long bpow(long long x, long long n, long long m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1; }
const int inf = 1 << 30;
const long long p = 1000003133;
const long long b = 1e3+9;
const long long inv = bpow(b, p-2, p);

char g(char a, char b) {
  for (auto x : { 'A', 'B', 'C' })
    if (x != a and x != b)
      return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<string> s(3);
  for (auto& x : s) cin >> x, x += x;

  int n = sz(s[0]) / 2;
  vector<long long> X(n, 1);
  for (int i = 1; i < n; i++) X[i] = (b * X[i-1]) % p;

  auto h = [&] (string x) {
    long long hs = 0;
    for (int i = 0; i < n; i++) {
      hs += X[i] * x[i];
      hs %= p;
    }
    return hs;
  };

  vector<unordered_map<long long, int>> S(3);
  for (int j : { 0, 1, 2 }) {
    string& x = s[j];
    long long hs = 0;
    for (int i = 0; i < n; i++) {
      hs += X[i] * x[i];
      hs %= p;
    }

    S[j][hs] = 0;
    for (int i = 1; i < n; i++) {
      hs += (p - x[i-1]);
      hs *= inv;
      hs += X[n-1] * x[i+n-1];
      hs %= p;
      if (!S[j].count(hs)) S[j][hs] = min(i, n-i);
      else S[j][hs] = min(S[j][hs], min(i, n-i));
    }
  }

  int ans = inf;
  for (int j : { 0, 1, 2 }) {
    string& x = s[j];
    string& y = s[(j+1)%3];
    for (int o = 0; o < n; o++) {
      int q = 1;
      long long hs = 0;
      for (int i = 0; i < n; i++) {
        if (x[i] == y[o+i]) {
          q = 0;
          break;
        } else {
          hs += X[i] * g(x[i], y[o+i]);
          hs %= p;
        }
      }

      if (q and S[(j+2) % 3].count(hs)) ans = min(ans, min(o, n-o) + S[(j+2) % 3][hs]);
    }
  }

  cout << (ans == inf ? -1 : ans) << endl;
}

