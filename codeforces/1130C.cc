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

int n;
vector<string> A;
pair<int, int> s, t;
vector<pair<int, int>> a, b;
int V[51][51];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s.fst >> s.snd >> t.fst >> t.snd;
  s.fst--, s.snd--, t.fst--, t.snd--;
  A.assign(n, "");
  for (auto& r : A) cin >> r;

  queue<pair<int, int>> Q;
  Q.push(s);
  while (!Q.empty()) {
    auto v = Q.front();
    Q.pop();
    if (V[v.fst][v.snd]) continue;
    V[v.fst][v.snd] = true;
    a.push_back(v);
    if (v.fst+1 < n and A[v.fst+1][v.snd] == '0') Q.push({v.fst+1, v.snd});
    if (v.fst-1 >= 0 and A[v.fst-1][v.snd] == '0') Q.push({v.fst-1, v.snd});
    if (v.snd < n and A[v.fst][v.snd+1] == '0') Q.push({v.fst, v.snd+1});
    if (v.snd-1 >= 0 and A[v.fst][v.snd-1] == '0') Q.push({v.fst, v.snd-1});
  }

  if (V[t.fst][t.snd]) {
    cout << 0 << endl;
    return 0;
  }

  Q.push(t);
  while (!Q.empty()) {
    auto v = Q.front();
    Q.pop();
    if (V[v.fst][v.snd]) continue;
    V[v.fst][v.snd] = true;
    b.push_back(v);
    if (v.fst+1 < n and A[v.fst+1][v.snd] == '0') Q.push({v.fst+1, v.snd});
    if (v.fst-1 >= 0 and A[v.fst-1][v.snd] == '0') Q.push({v.fst-1, v.snd});
    if (v.snd < n and A[v.fst][v.snd+1] == '0') Q.push({v.fst, v.snd+1});
    if (v.snd-1 >= 0 and A[v.fst][v.snd-1] == '0') Q.push({v.fst, v.snd-1});
  }

  int ans = 1<<30;
  for (auto& x : a) {
    for (auto& y : b) {
      ans = min(ans, (x.fst - y.fst) * (x.fst - y.fst) + (x.snd - y.snd) * (x.snd - y.snd));
    }
  }

  cout << ans << endl;

}

