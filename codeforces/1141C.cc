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

int n;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n-1, 0);
  for (auto& a : A) cin >> a;

  vector<int> ans(n);
  ans[0] = 0;
  set<int> S;
  S.insert(0);
  int u = 0;
  for (int i = 0; i < n-1; i++) {
    // p[i+1] - p[i] = A[i]
    ans[i+1] = A[i] + ans[i];
    S.insert(ans[i+1]);
    u = max(u, ans[i+1]);
  }

  if (S.size() == n and u - (*begin(S)) == n-1) {
    int m = 1 - *(begin(S));
    for (auto& a : ans) cout << a+m << ' ';
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}

