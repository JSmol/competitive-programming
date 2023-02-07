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

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
ll g(vector<pair<ll ,ll>>& a) {
  ll x = 0, y = 0;
  for (int i : {0, 1, 2}) x += a[i].fst, y = max(y, a[i].snd);
  ll ans = x * y;

  // i above j
  for (int i = 0; i < 3; i++) {
    x = y = 0;
    for (int j = 0; j < 3; j++) {
      if (i == j) continue;
      y = max(y, a[i].snd + a[j].snd);
      x += a[j].fst;
    }

    x = max(x, a[i].fst);
    for (int j = 0; j < 3; j++) {
      if (i == j) continue;
      if (a[i].fst <= a[j].fst) {
        for (int k = 0; k < 3; k++)
          if (k != j and k != i) 
            y = min({y, a[i].snd + a[j].snd, a[k].snd});
      }
    }

    ans = min(ans, x * y);
    debug(ans);
    debug(i)
    debug(x);
    debug(y);
  }

  return ans;
}
ll f(vector<pair<ll ,ll>>& a) {
  ll x = 0, y = 0;
  for (int i : {0, 1, 2}) x += a[i].fst, y = max(y, a[i].snd);
  ll ans = x * y;

  // i above j
  for (int i = 0; i < 3; i++) {
    x = 0;
    for (int j = 0; j < 3; j++) {
      if (i == j) continue;
      x += a[j].fst;
    }

    x = max(a[i].fst, x);

    for (int j = 0; j < 3; j++) {
      if (i == j) continue;
      for (int k = 0; k < 3; k++) {
        if (i == k or j == k) continue;
        if (a[i].fst <= a[j].fst) {
          y = max(a[i].snd + a[j].snd, a[k].snd);
          ans = min(x*y, ans);
        } else {
          y = max(a[i].snd + a[j].snd, a[i].snd + a[k].snd);
          ans = min(x*y, ans);
        }
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<pair<ll, ll>> a(3);
    cin >> a[0].fst >> a[0].snd >> a[1].fst >> a[1].snd >> a[2].fst >> a[2].snd;

    ll ans = 1ll << 62;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 3; j++) {
        if (i & (1 << j)) {
          swap(a[j].fst, a[j].snd);
        }
      }

      ans = min(ans, f(a));

      for (int j = 0; j < 3; j++) {
        if (i & (1 << j)) {
          swap(a[j].fst, a[j].snd);
        }
      }
    }

    cout << ans << endl;
  }
}

