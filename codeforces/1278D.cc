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

int n;
vector<int> V;
vector<vector<int>> G(n);
int dfs(int v) {
  int x = 1; V[v] = 1;
  for (auto& a : G[v]) {
    if (!V[a])
      x += dfs(a);
  }
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> l(n), r(n), A(2*n+1, -1);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    A[l[i]] = i; A[r[i]] = i;
  }

  int m = 0;
  set<pair<int, int>> S;
  G.assign(n, {});
  for (auto& i : A) {
    if (i != -1) {
      if (S.count({r[i], i})) {
        for (auto& x : S) {
          if ((l[i] < l[x.snd] and r[i] < x.fst)
           or (l[x.snd] < l[i] and x.fst < r[i]))
            G[x.snd].push_back(i), G[i].push_back(x.snd), m++;
          else break;
        }
        S.erase({r[i], i});
      } else {
        S.insert({r[i], i});
      }
    }

    if (m >= n) {
      cout << "NO" << endl;
      return 0;
    }
  }

  V.assign(n, 0);
  if (n == dfs(0)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

