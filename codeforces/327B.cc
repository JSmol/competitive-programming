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

const int m = 1300000;
int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> A(m, 1);
  vector<int> ans;
  for (int i = 2; i < m and ans.size() < n; i++) {
    if (A[i]) {
      ans.push_back(i);
      int k = i;
      while (k < m) {
        A[k] = 0;
        k+=i;
      }
    }
  }

  assert(ans.size() == n);
  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

