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

int n, m, c;
vector<pair<int, int>> A;
vector<int> d;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(m, {});
  for (int i = 0; i < m; i++) cin >> A[i].fst, A[i].snd = i;

  sort(begin(A), end(A));
  c = 1<<30;
  for (int i = 0, j = 0; i < m; i = j) {
    j = i+1;
    while (j < m and A[i].fst == A[j].fst) j++;
    
    c = min(c, j-i);
    d.push_back(i);
  }

  if (d.size() < n) {
    cout << string(m, '0') << endl;
    return 0;
  }

  string ans(m, '0');
  for (int i = 0, o = 0; i < c; i++) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (A[d[j]+o].snd > A[d[k]+o].snd)
        k = j;
    }
    ans[A[d[k]+o].snd] = '1';
    o++;
  }
  cout << ans << endl;
}

