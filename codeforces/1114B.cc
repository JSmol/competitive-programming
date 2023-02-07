#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

typedef long long ll;
ll n, m, k;
vector<pair<int, int>> A;
vector<int> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  A.assign(n, {});
  for (int i = 0; i < n; i++) cin >> A[i].fst, A[i].snd = i;

  sort(begin(A), end(A));
  ll s = 0;
  for (int i = 0; i < m*k; i++) {
    s += A[n-i-1].fst;
    ans.push_back(A[n-i-1].snd + 1);
  }

  sort(begin(ans), end(ans));
  cout << s << endl;

  for (int i = 1; i <= m*k-m; i++)
    if (i % m == 0) 
      cout << ans[i-1] << ' ';
}

