#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a+1; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n;
vector<pair<int, int>> A;
vector<int> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, {});
  for (auto& a : A) cin >> a.fst >> a.snd, a.fst--, a.snd--;

  if (n == 3) {
    cout << "1 2 3" << endl;
    return 0;
  }

  ans.assign(n, 0);
  for (int i = 0; i < n-1; i++) {
    pair<int, int> a = A[ans[i]];
    if (A[a.snd].fst == a.fst or A[a.snd].snd == a.fst)
      ans[i+1] = a.snd;
    if (A[a.fst].fst == a.snd or A[a.fst].snd == a.snd)
      ans[i+1] = a.fst;
  }

  cout << ans << endl;
}

