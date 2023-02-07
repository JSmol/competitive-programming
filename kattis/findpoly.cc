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

struct UF {
  int n; vector<int> A;
  UF (int size) {
    n = size; A = vector<int>(n);
    iota(begin(A), end(A), 0);
  }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

int deg[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string input, s;
  while (getline(cin, s)) input += s;
  for (auto& c : input)
    if (!isdigit(c)) c = ' ';

  stringstream ss(input);

  int n = 0;
  UF uf(1000);
  int a, b, c, d;
  map<pair<int, int>, int> M;
  while (ss >> a >> b >> c >> d) {
    if (!M.count({a, b})) M[{a, b}] = n++;
    if (!M.count({c, d})) M[{c, d}] = n++;
    deg[M[{a, b}]]++;
    deg[M[{c, d}]]++;
    uf.merge(M[{a, b}], M[{c, d}]);
  }

  vector<set<int>> A(n);
  for (int i = 0; i < n; i++) {
    A[uf.find(i)].insert(i);
  }

  int ans1 = 0, ans2 = 0;
  for (auto& S : A) {
    bool p = true;
    for (auto& i : S) {
      if (deg[i] != 2) p = false;
    }

    if (!S.empty()) ans1++;
    if (!S.empty() and p) ans2++;
  }

  cout << ans1 << ' ' << ans2 << endl;
}

