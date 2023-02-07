#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

int n, m;
map<string, int> M;
vector<pair<pair<int, int>, string>> A;

int f() {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;

  for (int s = 0; s < n; s++)
    PQ.push({abs(A[s].fst.fst) + abs(A[s].fst.snd), {s, 1 << M[A[s].snd]}});

  map<pair<int, int>, int> D;
  while (!PQ.empty()) {
    int d = PQ.top().fst, v = PQ.top().snd.fst, b = PQ.top().snd.snd;
    PQ.pop();

    if (D.count({v, b})) continue;
    else D[{v, b}] = d;
    
    if (v == -1 and b == (1 << m) - 1) return d;
    if (b == (1 << m) - 1) PQ.push({d + abs(A[v].fst.fst) + abs(A[v].fst.snd), {-1, b}});
    else {
      for (int a = 0; a < n; a++)
        PQ.push({d + abs(A[v].fst.fst - A[a].fst.fst) + abs(A[v].fst.snd - A[a].fst.snd) , {a, b | (1 << M[A[a].snd])}});
    }
  }
  assert(false);
}

int main() {
  cin >> n;
  A.assign(n, {});
  for (int i = 0, x, y; i < n; i++) {
    string s;
    cin >> x >> y >> s;
    A[i] = {{x, y}, s};
    if (!M.count(s)) M[s] = m++;
  }

  int ans = f();
  cout << ans << endl;
}
