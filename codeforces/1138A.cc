#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a;

  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i;
    while (j < n and A[i] == A[j]) j++;
    int k = j;
    while (k < n and A[j] == A[k]) k++;
    ans = max(ans, min(2*(j-i), 2*(k-j)));
  }

  cout << ans << endl;

}

