#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int m, q;
int isa[505][505];
int hasa[505][505];
map<string, int> M;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 0;
  cin >> m >> q;
  while (m--) {
    string x, y, rel;
    cin >> x >> rel >> y;
    if (!M.count(x)) M[x] = n++;
    if (!M.count(y)) M[y] = n++;
    if (rel == "is-a") {
      isa[M[x]][M[y]] = 1;
    } else {
      hasa[M[x]][M[y]] = 1;
    }
  }

  for (int i = 0; i < n; i++)
    isa[i][i] = 1;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        isa[i][j] |= isa[i][k] and isa[k][j];
        hasa[i][j] |= hasa[i][k] and hasa[k][j];
        hasa[i][j] |= hasa[i][k] and isa[k][j];
        hasa[i][j] |= isa[i][k] and hasa[k][j];
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    string x, y, rel;
    cin >> x >> rel >> y;
    if (rel == "is-a") {
      cout << "Query " << i << ": " << (isa[M[x]][M[y]] ? "true" : "false") << endl;
    } else {
      cout << "Query " << i << ": " << (hasa[M[x]][M[y]] ? "true" : "false") << endl;
    }
  }
}

