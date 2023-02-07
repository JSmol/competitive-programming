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

int bpow(int x, int n, int m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1; }
// typedef long long ll;
// template<typename T>
// T bpow(T x, ll n, T m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  vector<int> p(1e6+1, 1);
  for (long long i = 2; i <= int(1e6); i++) {
    if (p[i]) {
      for (long long j = i*i; j <= int(1e6); j += i) {
        p[j] = 0;
      }
    }
  }

  int x; vector<int> a; 
  while (cin >> x and x != 0) a.push_back(x);

  map<int, int> primes;
  for (auto& n : a) {

    for (int i = 2; i <= 5; i++) {
      if (p[i]) {
        primes[i] = n / i;
        for (int j = i*i; j <= n; j *= i) {
          primes[i] += n / j;
        }
      }
    }

    primes[2] -= primes[5];
    primes[5] = 0;
    int ans = 1;
    for (auto& [p, c] : primes) {
      ans = (ans * bpow(p, c, 10)) % 10;
    }

    for (long long i = 7; i <= n; i++) {
      if (p[i]) {
        // primes[i] = n / i;
        ans = (ans * bpow(int(i % 10ll), n / i, 10)) % 10;
        for (long long j = i*i; j <= n; j *= i) {
          // primes[i] += n / j;
          ans = (ans * bpow(int(i % 10ll), n / j, 10)) % 10;
        }
      }
    }

    cout << ans << '\n';
  }
}

