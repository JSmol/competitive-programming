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

struct UF {
  int n; vector<int> A;
  UF (int size) : n(size), A(n) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

bool find(string s, char x) {
  for (auto& c : s) if (x == c) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> A(n);
  for (auto& a : A) cin >> a, sort(all(a));
  sort(all(A));

  UF u(n);
  for (char i = 'a'; i <= 'z'; i++) {
    int p = -1;
    for (int j = 0; j < n; j++) {
      if (p != -1 and find(A[j], i)) {
        u.merge(p, j);
      } else
      if (find(A[j], i)) {
        p = j;
      }
    }
  }

  int ans = 0;
  set<int> S;
  for (auto& x : u.A) {
    if (!S.count(x)) ans++, S.insert(x);
  }

  cout << ans << endl;
}

