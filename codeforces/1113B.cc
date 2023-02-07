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

int n, s;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (int i = 0; i < n; i++) {
    int& a = A[i];
    cin >> a;
    s += a;
  }

  sort(begin(A), end(A));
  int ans = s;
  for (int i = 0; i < n; i++) {
    int& a = A[i];
    int j = 2;
    while (j*j <= a) {
      if (a%j == 0) {
        for (int k = 0; k < n; k++) {
          if (k == i) continue;
          int& b = A[k];
          ans = min(ans, s + (b*j-b) - (a-a/j));
          break;
        }
      }
      j++;
    }
  }

  cout << ans << endl;

}

