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

int n, m, p;
vector<int> S, C;
vector<string> A;

bool g(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> p;
  S.assign(p, 0);
  C.assign(p, 0);
  for (auto& s : S) cin >> s;
  A.assign(n, {});
  for (auto& r : A) cin >> r;

  priority_queue<pair<tuple<int, int, int>, pair<int, int>>,
          vector<pair<tuple<int, int, int>, pair<int, int>>>,
         greater<pair<tuple<int, int, int>, pair<int, int>>>> Q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char& c = A[i][j];
      if (c != '.' and c != '#')
        Q.push({{1, c - '0', 0}, {i, j}}),
        C[c - '0' - 1]++;
    }
  }

  while (!Q.empty()) {
    int k = get(Q.top().fst, 0), a = get(Q.top().fst, 1), c = get(Q.top().fst, 2);
    auto l = Q.top().snd;
    Q.pop();

    for (int i : {-1, 0, 1}) {
      for (int j : {-1, 0, 1}) {
        if (i != 0 and j != 0) continue;

        int x = l.fst + i, y = l.snd + j;
        if (g(x, y) and A[x][y] == '.') {
          if (c < S[a-1] - 1) {
            Q.push({{k, a, c+1}, {x, y}});
            A[x][y] = '0' + a;
            C[a-1]++;
          } else {
            Q.push({{k+1, a, 0}, {x, y}});
            A[x][y] = '0' + a;
            C[a-1]++;
          }
        }
      }
    }
  }

  cout << C << endl;
}

