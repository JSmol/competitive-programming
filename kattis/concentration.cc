#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int n, i[2];
int s[2];
set<int> s2;
vector<int> C, V, A[2];
void f(int p) {

  if (!s2.empty()) {
    s[p] += sz(s2);
    s2.clear();
  }

  while (i[p] < n and V[A[p][i[p]]]) i[p]++;
  if (i[p] == n) return;

  V[A[p][i[p]]] = 1;
  C[A[p][i[p]] / 2]++;
  if (C[A[p][i[p]] / 2] == 2) {
    s[p]++;
    f(p);
  } else {
    int c = A[p][i[p]];
    while (i[p] < n and V[A[p][i[p]]]) i[p]++;
    V[A[p][i[p]]] = 1;
    C[A[p][i[p]] / 2]++;
    if (C[c / 2] == 2) {
      s[p]++;
      f(p);
    } else {
      if (C[A[p][i[p]] / 2] == 2) s2.insert(A[p][i[p]]);
      f(!p);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A[0].assign(2*n, 0);
  for (auto& a : A[0]) cin >> a;
  A[1].assign(2*n, 0);
  for (auto& a : A[1]) cin >> a;

  C.assign(n, 0);

  V.assign(2*n, 0);
  n *= 2;
  f(0);

  if (s[0] < s[1]) {
    cout << 1 << endl;
  }

  if (s[1] < s[0]) {
    cout << 0 << endl;
  }

  if (s[0] == s[1]) {
    cout << -1 << endl;
  }
}
