#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int t;
int a, b;
vector<bool> V;

int f(int k) {
  for (int i = 2; i * i <= k; i++)
    if (k % i == 0) return false;
  return true;
}

int g(int k) {
  int a = 1;
  while (k--) a = 10 * a;
  return a;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> a >> b;
    V.assign(10000, 0);

    queue<pair<int, int>> Q;
    Q.push({a, 0});

    while (!Q.empty()) {
      int v = Q.front().fst, d = Q.front().snd;
      Q.pop();

      if (V[v]) continue;
      V[v] = true;

      if (v == b) {
        cout << d << endl;
        break;
      }

      for (int i = 0, m; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
          if (j == 0 and i == 3)
            continue;

          m = (v / g(i+1)) * g(i+1);
          m += j * g(i);
          if (i > 0)
            m += v % g(i);

          if (f(m))
            Q.push({m, d+1});
        }
      }
    }
  }
}

