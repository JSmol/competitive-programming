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
int n;
vector<pair<int, int>> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(2*n, {});
  for (int i = 0; i < 2*n; i++) cin >> A[i].fst, A[i].snd = i;

  sort(begin(A), end(A));
  ll x = A[0].snd, y = A[1].snd;
  for (int i = 1; i < n; i++) {
    x += abs(A[2*i].snd - A[2*(i-1)].snd);
    y += abs(A[2*i+1].snd - A[2*(i-1)+1].snd);
  }

  cout << x + y << endl;
}

