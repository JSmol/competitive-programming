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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

struct union_find {
  int n; vector<int> A;
  union_find (int size) {
    n = size; A = vector<int>(n);
    iota(begin(A), end(A), 0);
  }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

int n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  union_find uf(n+1);
  for (int i = 0, k, a, b; i < m; i++) {
    cin >> k; k--;
    if (k < 0) continue;

    cin >> a;
    while (k--) cin >> b, uf.merge(a, b);
  }

  vector<int> A(n+1);
  for (int i = 1; i <= n; i++) {
    A[uf.find(i)]++;
  }

  for (int i = 1; i <= n; i++) {
    cout << A[uf.find(i)] << ' ';
  }
  cout << endl;
}

