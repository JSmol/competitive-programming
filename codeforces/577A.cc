#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

int n, x;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> x;

  set<int> S;
  int ans = 0;
  for (int i = 1; i*i <= x; i++) {
    if (x%i == 0) {
      S.insert(i);
      S.insert(x/i);
    }
  }

  for (auto& e : S) {
    if (e <= n and x/e <= n) {
      ans++;
    }
  }
  cout << ans << endl;
}

