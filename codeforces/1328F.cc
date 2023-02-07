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
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  map<int, int> c;
  for (auto& x : a) cin >> x, c[x]++;
  sort(all(a));

  map<ll, ll> cl, cr;
  cl[a[0]] = 0, cr[a[n-1]] = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i+1;
    while (j < n and a[i] == a[j]) j++;
    if (j < n) cl[a[j]] = cl[a[i]] + (a[j] - a[i]) * ll(j);
  }

  for (int i = n-1, j = n-1; ~i; i = j) {
    j = i-1;
    while (~j and a[i] == a[j]) j--;
    if (~j) cr[a[j]] = cr[a[i]] + (a[i] - a[j]) * ll(n-j-1);
  }

  ll ans = 1ll << 60;
  for (int i = 0, j = 0; i < n; i = j) {

    int nums = c[a[i]];
    ll cost = 0;
    if (nums >= k) {
      ans = 0;
      break;
    }

    cost += cl[a[i]]; // try left first 
    nums += (lower_bound(all(a), a[i]) - begin(a));
    if (nums >= k) {
      ans = min(ans, cost - (nums - k));
    } else {
      cost += cr[a[i]];
      nums += n - (upper_bound(all(a), a[i]) - begin(a));
      if (nums >= k) ans = min(ans, cost - (nums - k));
    }

    nums = c[a[i]]; // try right first
    cost = 0;
    cost += cr[a[i]];
    nums += n - (upper_bound(all(a), a[i]) - begin(a));
    if (nums >= k) {
      ans = min(ans, cost - (nums - k));
    } else {
      cost += cl[a[i]];
      nums += (lower_bound(all(a), a[i]) - begin(a));
      if (nums >= k) ans = min(ans, cost - (nums - k));
    }

    j = i+1;
    while (j < n and a[i] == a[j]) j++;
  }

  cout << ans << endl;
}

