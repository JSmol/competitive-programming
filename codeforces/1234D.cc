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

struct fenwick {
  vector<int> A; int n;
  fenwick(vector<int>& x, int s) { n = s+1; A.assign(n, 0); for (int i = 0; i < n; i++) add(i+1, x[i]); }
  void add(int i, int v) { while (i < n) A[i] += v, i += i & -i; } 
  int query(int i) { int s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;

  int n = (int) s.size();
  vector<vector<int>> A(26, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      A[c][i] = (s[i] - 'a' == c);
    }
  }

  vector<fenwick> X;
  for (int c = 0; c < 26; c++) {
    X.push_back({A[c], n});
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int i; char c;
      cin >> i >> c;

      X[s[i-1] - 'a'].add(i, -1);
      X[c - 'a'].add(i, 1);
      s[i-1] = c;

    } else {
      int l, r;
      cin >> l >> r;

      int ans = 0;
      for (int c = 0; c < 26; c++) ans += (X[c].query(r) - X[c].query(l-1) > 0);

      cout << ans << endl;
    }
  }
}

