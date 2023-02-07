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

typedef long double ld;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int p, d;
  cin >> p >> d;
  vector<pair<int, int>> A(d);
  while (p--) {
    int i, a, b;
    cin >> i >> a >> b;
    A[i-1].fst += a;
    A[i-1].snd += b;
  }

  ld wa = 0, wb = 0, tot = 0;
  for (int i = 0; i < d; i++) {
    if (A[i].snd < A[i].fst) {
      int t = A[i].fst + A[i].snd;
      int a = A[i].fst - (t/2+1);
      int b = A[i].snd;
      wa += a;
      wb += b;
      tot += t;
      cout << 'A' << ' ' << a << ' ' << b << endl;
    } else {
      int t = A[i].fst + A[i].snd;
      int a = A[i].fst;
      int b = A[i].snd - (t/2+1);
      cout << 'B' << ' ' << a << ' ' << b << endl;
      wa += a;
      wb += b;
      tot += t;
    }
  }
  cout << setprecision(9) << fixed << abs(wa-wb) / tot << endl;
}

