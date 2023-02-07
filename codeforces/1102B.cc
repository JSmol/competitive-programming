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

int n, k;
vector<pair<int, int>> A;
vector<int> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, {});
  for (int i = 0; i < n; i++) cin >> A[i].fst, A[i].snd = i;

  sort(begin(A), end(A));
  ans.assign(n, 0);
  int c = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i+1;
    while (j < n and A[j].fst == A[i].fst) j++;

    if (j-i > k) {
      cout << "NO" << endl;
      return 0;
    }

    for (int l = i; l < j; l++) {
      ans[A[l].snd] = c+1;
      c++;
      c%=k;
    }
  }

  cout << "YES" << endl;
  cout << ans << endl;


}

