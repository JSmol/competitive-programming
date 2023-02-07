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
ll n;
vector<ll> B, A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  B.assign(n/2, 0);
  for (auto& b : B) cin >> b;

  A.assign(n, 0);
  A[0] = 0;
  A[n-1] = B[0];
  for (int i = 1; i < n/2; i++) {
    if (B[i] < B[i-1]) {
      A[i] = A[i-1];
      A[n-i-1] = B[i] - A[i];
    } else {
      ll x = B[i] - B[i-1];
      A[i] = A[i-1] + x;
      A[n-i-1] = B[i] - A[i];
    }
  }

  cout << A << endl;
}

