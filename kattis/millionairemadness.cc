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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int A[1010][1010];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> A[i][j];

  int ans = 0;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;
  PQ.push({0, {0, 0}});
 
  bool V[1010][1010];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      V[i][j] = false;

  while (!PQ.empty()) {
    int d = PQ.top().fst;
    pair<int, int> v = PQ.top().snd;
    PQ.pop();

    if (V[v.fst][v.snd]) continue;
    V[v.fst][v.snd] = true;

    if (v.fst == n-1 and v.snd == m-1) {
      ans = d;
      break;
    }

    for (int i : {-1, 1}) {
      if (0 <= v.fst + i and v.fst + i < n) 
        PQ.push({max(d, A[v.fst + i][v.snd] - A[v.fst][v.snd]), {v.fst + i, v.snd}});
      if (0 <= v.snd + i and v.snd + i < m) 
        PQ.push({max(d, A[v.fst][v.snd + i] - A[v.fst][v.snd]), {v.fst, v.snd + i}});
    }
  }

  cout << ans << endl;
}

