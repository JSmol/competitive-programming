#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, p = 0;
  cin >> n;
  vector<int> A(n*2);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i+n] = A[i];
    if (A[i] == 1) p = true;
  }

  if (!p) {
    cout << 0 << endl;
    return 0;
  }

  n *= 2;
  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i+1;
    while (A[i] == 1 and j < n and A[i] == A[j]) j++;
    ans = max(ans, j - i);
  }
  cout << ans << endl;
}

