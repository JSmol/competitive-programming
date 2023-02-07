#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define emplace emplace_back

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

typedef long long ll;
template<typename T>
T bpow(T x, ll n) { return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n; ll m = n;
    vector<pair<int, int>> A;
    for (ll i = 2; i*i <= n; i++) {
      int a = 0;
      while (m % i == 0) m /= i, a++;
      if (a > 0) A.emplace(i, a);
    }

    if (m > 1) A.emplace(m,  1);

    if (sz(A) >= 3) {
      ll a = A[0].fst;
      ll b = A[1].fst;
      ll c = n / (A[0].fst * A[1].fst);
      assert(a*b*c == n);
      cout << "YES" << endl;
      cout << a << ' ' << b << ' ' << c << endl;
    }

    if (sz(A) == 2) {
      int x = A[0].snd + A[1].snd;
      if (x >= 4) cout << "YES" << endl << A[0].fst << ' ' << A[1].fst << ' ' << n / (A[0].fst * A[1].fst) << endl;
      else cout << "NO" << endl;
    }

    if (sz(A) == 1) {
      if (A[0].snd >= 6) cout << "YES" << endl << A[0].fst << ' ' << bpow(A[0].fst, 2) << ' ' << n / (A[0].fst * bpow(A[0].fst, 2)) << endl;
      else cout << "NO" << endl;
    }
  }
}

