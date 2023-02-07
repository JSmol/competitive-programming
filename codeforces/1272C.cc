#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  set<char> S;
  for (char i = 0, x; i < k; i++) cin >> x, S.insert(x);

  ll ans = 0;
  for (int i = 0, j = 1; i < n; i = j, j++) {
    if (!S.count(s[i])) continue;
    while (j < n and S.count(s[j])) j++;
    ll x = j-i;
    ans += (x * (x+1)) / 2;
  }

  cout << ans << endl;
}

