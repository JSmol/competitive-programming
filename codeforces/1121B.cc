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

int n, m;
vector<int> A;
int s[1010][1010];
int C[202020];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      C[A[i] + A[j]]++;

  for (int i = 0; i < 202020; i++)
    m = max(C[i], m);

  cout << m << endl;
}

