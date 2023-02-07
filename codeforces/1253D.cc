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

struct UF {
  int n; vector<int> A;
  UF (int size) : n(size), A(n) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  UF uf(n);
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b; a--; b--;
    uf.merge(a, b);
  }

  vector<int> X(n, 0);
  for (int i = 0; i < n; i++) {
    X[uf.find(i)]++;
  }

  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    if (X[uf.find(i)] > 1) {
      for (j = i+1; j < n; j++) {
        if (uf.connected(i, j)) break;
      }

      int c = 0;
      for (int k = i; k < j; k++) {
        if (!uf.connected(i, k)) {
          X[uf.find(i)] += X[uf.find(k)];
          uf.merge(i, k);
          ans++;
        }
        c++;
      }

      X[uf.find(i)] -= c;
    } else {
      j = i+1;
    }
  }

  cout << ans << endl;
}

