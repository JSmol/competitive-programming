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

int n, c;
vector<int> A;

int f(int i, int k) {
  if (i == n) return 0;
  if (k and A[i] + k <= c)
    return f(i+1, A[i] + k) + 1;
  if (k and A[i] + k > c)
    return f(i+1, k);
  if (!k and A[i] <= c)
    return max(f(i+1, A[i]) + 1, f(i+1, 0));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> c;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  cout << f(0, 0) << endl;

}

