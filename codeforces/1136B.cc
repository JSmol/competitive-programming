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

int n, k;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  int ans = 6;

  if (n > 2) {
    ans += min((k - 1) - 1, (n - k) - 1) * 3;
    ans += max((k - 1), (n - k)) * 3;

    if (k != 1 and k != n) 
      ans += min((k-1), (n-k));
  }

  cout << ans << endl;
}

