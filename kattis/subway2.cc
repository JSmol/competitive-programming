#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)
#define sqr(X) (X) * (X)

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

typedef long long ll;
typedef double ld;
pair<int, int> s, t;
vector<vector<pair<int, int>>> A;

const ld mm = 166.666666666666666666666666666666666666666;

ld dist(pair<ll, ll> a, pair<ll, ll> b) {
  return sqrt(sqr(a.fst-b.fst) + sqr(a.snd-b.snd));
}

ld dijkstra() {
  priority_queue<pair<ld, pair<int, int>>, vector<pair<ld, pair<int, int>>>, greater<pair<ld, pair<int, int>>>> PQ;
  PQ.push({0.0, s});
  set<pair<int, int>> S;

  while (!PQ.empty()) { 
    pair<int, int> v = PQ.top().snd;
    ld d = PQ.top().fst;
    PQ.pop();

    if (v == t) return d;

    if (S.count(v) == 1) continue;
    S.insert(v);
  
    PQ.push({dist(v, t)/mm + d, t});

    for (auto& a : A) {
      auto it = find(all(a), v);
      if (it != end(a)) {
        if (it != begin(a)) {
          PQ.push({dist(v, *(it-1))/(4*mm) + d, *(it-1)});
        }
        if (it+1 != end(a)) {
          PQ.push({dist(v, *(it+1))/(4*mm) + d, *(it+1)});
        }
      }

      for (auto& u : a) {
        PQ.push({dist(v, u)/mm + d, u});
      }
    }
  }
  assert(false);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s.fst >> s.snd >> t.fst >> t.snd;

  pair<int, int> p, q;
  while (cin >> p.fst >> p.snd) {
    A.push_back({});
    A.back().push_back(p);
    while (cin >> q.fst >> q.snd and q.fst != -1) {
      A.back().push_back(q);
    }
  }

  cout << round(dijkstra()) << endl;
}

