#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, s, d, t = 0;
  cin >> n >> m >> s >> d;
  vector<int> A(s);
  for (auto& a : A) cin >> a, t += a;

  vector<int> I(s);
  iota(all(I), 0);
  sort(all(I), [&] (const int a, const int b) -> bool { return A[a] < A[b]; });
  
  vector<int> ans(s);
  for (int i = 0; i < s and n > 0; i++) {
    ans[I[i]] = min(n, d - A[I[i]]);
    n -= ans[I[i]];
    t -= A[I[i]];
  }

  if (n == 0 and t >= m) {
    for (auto& a : ans) cout << a << ' ';
    cout << endl;
  } else {
    cout << "impossible" << endl;
  }
}

