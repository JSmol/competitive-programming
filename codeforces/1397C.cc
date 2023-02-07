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
template<typename T>
T bpow(T x, ll n, T m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ll n; cin >> n;
  vector<ll> A(n);
  for (auto& a : A) cin >> a;

  if (n == 1) {
    cout << 1 << ' ' << 1 << endl;
    cout << -A[0] << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 0 << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 0 << endl;
    return 0;
  }

  if (n == 2) {
    cout << 1 << ' ' << 1 << endl;
    cout << -A[0] << endl;
    cout << 2 << ' ' << 2 << endl;
    cout << -A[1] << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 0 << endl;
    return 0;
  }


  if (n == 3) {
    cout << 1 << ' ' << 1 << endl;
    cout << -A[0] << endl;
    cout << 2 << ' ' << 2 << endl;
    cout << -A[1] << endl;
    cout << 3 << ' ' << 3 << endl;
    cout << -A[2] << endl;
    return 0;
  }

  vector<int> p(n+1, 1); p[0] = p[1] = 0;
  for (ll i = 2; i <= n; i++) {
    for (ll j = i+i; j <= n; j += i) {
      p[j] = 0;
    }
  }

  ll m;
  for (m = (n+1)/2; m <= n; m++)
    if (p[m] and n % m != 0) break;

  assert(m != n);

  cout << 1 << ' ' << n << endl;
  for (ll i = 0; i < n; i++) {
    if (A[i] > 0) {
      ll k = ((A[i] % m) * bpow(ll(n), m-2, m)) % m;
      cout << -k * n << ' ';
      A[i] -= k*n;
    } else {
      ll k = ((m-(A[i] % m)) * bpow(ll(n), m-2, m)) % m;
      cout << k * n << ' ';
      A[i] += k*n;
    }
  }

  cout << endl;
  // debug(A);

  cout << 1 << ' ' << m << endl;
  for (ll i = 0; i < m; i++) {
    assert(A[i] % m == 0);
    ll k = A[i] / m;
    cout << -k * m << ' ';
    A[i] -= k * m;
  }

  cout << endl;
  // debug(A);

  cout << n-m+1 << ' ' << n << endl;
  for (ll i = n-m; i < n; i++) {
    assert(A[i] % m == 0);
    ll k = A[i] / m;
    cout << -k * m << ' ';
    A[i] -= k * m;
  }

  cout << endl;
  // debug(A);
}

