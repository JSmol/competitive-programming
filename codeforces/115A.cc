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
vector<vector<int>> A;
vector<int> D;

void f(int v, int d) {
  D[v] = d;
  for (auto& a : A[v])
    f(a, d+1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, {});
  D.assign(n,0);
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x == -1)
      D[i] = 1;

    A[x-1].push_back(i);
  }

  for (int i = 0; i < n; i++)
    if (D[i] == 1)
      f(i, 1);

  cout << *max_element(begin(D),end(D)) << endl;

}

