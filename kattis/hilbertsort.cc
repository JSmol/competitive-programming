#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
double time() { return double(clock()) / CLOCKS_PER_SEC; }

vector<int> f1(vector<int> a) {
  swap(a[1], a[3]);
  return a;
}

vector<int> f2(vector<int> a) {
  swap(a[0], a[2]);
  return a;
}

vector<double> asdf(int quad, double l, double d, double r, double u, double m1, double m2) {
  switch (quad) {
    case 0:
      return {l, d, m1, m2};
    case 1:
      return {l, m2, m1, u};
    case 2:
      return {m1, m2, r, u};
    case 3:
      return {m1, d, r, m2};
  }
}

vector<function<int(int, int, double, double)>> C = {
  [] (int x, int y, double m1, double m2) {
    return x <= m1 and y <= m2;
  },
  [] (int x, int y, double m1, double m2) {
    return x <= m1 and y > m2;
  },
  [] (int x, int y, double m1, double m2) {
    return x > m1 and y > m2;
  },
  [] (int x, int y, double m1, double m2) {
    return x > m1 and y <= m2;
  },
};

int n; double s; 
vector<int> x, y;
vector<int> f(vector<int>& I, vector<int> ord, double l, double d, double r, double u) {

  if (I.empty()) return {};
  if (sz(I) == 1) return I;

  vector<vector<int>> J(4);
  double m1 = (l+r) / 2, m2 = (d+u) / 2;
  for (int j = 0; j < 4; j++) {
    for (int i : I) {
      if (C[j](x[i], y[i], m1, m2)) {
        J[ord[j]].push_back(i);
      }
    }
  }

  for (int j = 0; j < 4; j++) {
    if (j == 0) {
      auto X = asdf(ord[j], l, d, r, u, m1, m2);
      J[j] = f(J[j], f1(ord), X[0], X[1], X[2], X[3]);
    } else
    if (j == 3) {
      auto X = asdf(ord[j], l, d, r, u, m1, m2);
      J[j] = f(J[j], f2(ord), X[0], X[1], X[2], X[3]);
    } else {
      auto X = asdf(ord[j], l, d, r, u, m1, m2);
      J[j] = f(J[j], (ord), X[0], X[1], X[2], X[3]);
    }
  }

  I.clear();
  for (int j = 0; j < 4; j++)
    for (auto i : J[j])
      I.push_back(i);

  return I;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;
  x.assign(n, 0); y.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  vector<int> I(n); iota(all(I), 0);
  auto ans = f(I, {0,1,2,3}, 0, 0, s, s);
  for (auto i : ans) {
    cout << x[i] << ' ' << y[i] << endl;
  }
}

