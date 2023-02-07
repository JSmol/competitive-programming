#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
double time() { return double(clock()) / CLOCKS_PER_SEC; }

pair<int, int> intersect(int a, int b, int c, int d) {
  return {max(a, c), min(b, d)};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int C = 1; C <= T; C++) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int l = a[0], h = a[0];
    for (int i = 1; i < n; i++) {
      auto [x, y] = intersect(l-k+1, h+k-1, a[i], a[i]+k-1);
      if (x <= y) {
        l = x;
        h = y;
      } else {
        goto NO;
      }
    }

    if (l <= a[n-1] and a[n-1] <= h) {
      cout << "YES" << endl;
    } else {
NO:
      cout << "NO" << endl;
    }
  }
}

// 
//       x
//   x x xx
//  xx x xxx
// xxxxxxxxx
