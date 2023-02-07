#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<pair<int, int>> A(4);
  A[0].snd = 0;
  A[1].snd = 1;
  A[2].snd = 2;
  A[3].snd = 3;

  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    A[0].fst += (a > x);
    A[1].fst += (b > y);
    A[2].fst += (a < x);
    A[3].fst += (b < y);
  }

  // 1110001
  // 1110000
  // 0111000
  // 0011100
  // 0001110
  // 0000111
  // 0000110
  // 0000011
  // 0000010
  // 0000001
  // 0000000
  //
  //
  //
  // 000001 
  // 000010 
  // 000100               000011
  // 001000 000101 000101 000110
  // 010000
  // 000000 000000
  // 000000 000000
  // 000000 000000
  // 000000 000000
  // 000000 000000
  // 000000 000000
  // 000000 000000
  // 000000 000000
  // 000000 000000

  sort(all(A), greater<>());
  if (A[0].snd == 0) {
    cout << A[0].fst << endl;
    assert(x+1 <= (int) 1e9);
    cout << x+1 << ' ' << y << endl;
  }
  if (A[0].snd == 1) {
    cout << A[0].fst << endl;
    assert(y+1 <= (int) 1e9);
    cout << x << ' ' << y+1 << endl;
  }
  if (A[0].snd == 2) {
    cout << A[0].fst << endl;
    assert(x-1 >= (int) 0);
    cout << x-1 << ' ' << y << endl;
  }
  if (A[0].snd == 3) {
    cout << A[0].fst << endl;
    assert(y-1 >= (int) 0);
    cout << x << ' ' << y-1 << endl;
  }
}
