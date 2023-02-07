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

const int inf = 1<<28;
const int maxn = 20*20;
int d, k, n, m;
vector<vector<pair<int, int>>> A;

int node(int a, int b) {
  return k*b + a;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> k >> d >> m;
  n = k * (d+1);

  A.assign(n, {});
  for (int i = 0, u, v, b, c; i < m; i++) {
    cin >> u >> v >> b >> c; u--; v--; b--;
    A[node(u, b)].push_back({node(v, b+1), c});
  }

  vector<int> C(n);
  for (int i = 0, a, b, c; i < d*k; i++) {
    cin >> a >> b >> c; a--; b--;
    C[node(a, b)] = c;
  }

  bool ans = true;
  for (int b = 0; b < d; b++) {
    for (int a = 0; a < k; a++) {
      for (auto& x : A[node(a, b)]) {
        if (x.snd <= C[node(a, b)]) {
          C[node(a, b)] -= x.snd;
          C[node(x.fst, b)] += x.snd;
        } else {
          ans = false;
        }
      }
    }

    for (int a = 0; a < k; a++) {
      assert(node(a, b+1) < n);
      C[node(a, b+1)] += C[node(a, b)];
      C[node(a, b)] = 0;
    }
  }
  
  cout << (ans ? "optimal" : "suboptimal") << endl;
}
