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

int n, m = 55;
string s;
int A[55][55];

int f(char x, bool y) {
  return y * 26 + (x - 'A');
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < 8; j += 2) {
      if (s[j] == '0') continue;
      int v = f(s[j], s[j+1] != '+');
      for (int k = 0; k < 8; k += 2) {
        if (k == j or s[k] == '0') continue;
        int u = f(s[k], s[k+1] == '+');
        A[v][u] = 1;
      }
    }
  }

  for (int k = 0; k < m; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        A[i][j] |= A[i][k] and A[k][j];
      }
    }
  }

  bool ans = false;
  for (int i = 0; i < m; i++)
    if (A[i][i] == 1)
      ans = true;

  cout << (ans ? "unbounded" : "bounded") << endl;
}

