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

vector<set<int>> A, col;
vector<int> ans;
int n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, {});
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--; v--;
    A[u].insert(v);
    A[v].insert(u);
  }

  ans.assign(n, -1);
  col.assign(3, {});
  for (int c = 0; c < 3; c++) {
    int v = -1;
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1) {
        col[c].insert(i);
        ans[i] = c;
        v = i;
        break;
      }
    }

    if (v != -1) {
      for (int i = 0; i < n; i++) {
        if (ans[i] == -1 and !A[v].count(i)) {
          col[c].insert(i);
          ans[i] = c;
        }
      }
    }
  }

  if (col[0].empty() or col[1].empty() or col[2].empty()) {
    cout << -1 << endl;
    return 0;
  }

  if (m != col[0].size() * col[1].size() + col[1].size() * col[2].size() + col[2].size() * col[0].size()) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = i+1; j < 3; j++) {
      for (auto& x : col[i]) {
        for (auto& y : col[j]) {
          if (!A[x].count(y)) {
            cout << -1 << endl;
            return 0;
          }
        }
      }
    }
  }

  for (auto& a : ans) cout << a+1 << ' ';
  cout << endl;
}

