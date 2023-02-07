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
char A[505][505];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> A[i][j];

  int c = 0;
  for (int i = 1; i < n-1; i++) {
    for (int j = 1; j < n-1; j++) {
      if (A[i][j] == 'X'
      and A[i+1][j+1] == 'X'
      and A[i+1][j-1] == 'X'
      and A[i-1][j+1] == 'X'
      and A[i-1][j-1] == 'X') {
        c++;
      }
    }
  }

  cout << c << endl;
}

