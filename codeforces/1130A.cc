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

int n;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  int x = 0, y = 0;
  for (auto& a : A) cin >> a, x += a > 0, y += a < 0;

  if (x >= (n+1)/2)
    cout << 1 << endl;
  else if (y >= (n+1)/2)
    cout << -1 << endl;
  else
    cout << 0 << endl;


}

