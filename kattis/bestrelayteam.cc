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

typedef long double ld;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<string> s(n);
  vector<ld> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i] >> b[i];
  }

  vector<int> I(n); iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return b[i] < b[j]; });

  auto score = [&] (int i) {
    ld ans = a[I[i]];
    int j = 0, k = 0;
    while (k < 3) {
      if (i == j) j++;
      ans += b[I[j]];
      k++;
      j++;
    }
    return ans;
  };

  ld best = 1 << 30;
  vector<string> ans;
  for (int i = 0; i < n; i++) {
    ld time = score(i);
    if (time < best) {
      best = time;
      ans = vector<string>();
      ans.push_back(s[I[i]]);
      int j = 0;
      while (sz(ans) < 4) {
        if (i == j) j++;
        ans.push_back(s[I[j]]);
        j++;
      }
    }
  }

  cout << setprecision(9) << fixed << best << endl;
  cout << ans[0] << endl;
  cout << ans[1] << endl;
  cout << ans[2] << endl;
  cout << ans[3] << endl;
}

