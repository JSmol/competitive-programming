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

template<typename T>
struct segment {
  int n; T id; function<T(T, T)> op;
  vector<T> S;
  segment(int n, T id, function<T(T, T)> op, vector<T>& A = {})
    : n(n), id(id), op(op), S(2*n, id) {
    for (int i = 0; i < sz(A); i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }
  void update(int x, T v) {
    for (S[x += n] = v; x > 1; x /= 2)
      S[x/2] = op(S[x], S[x^1]);
  }
  T query(int l, int r) {
    T ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};

struct eulertour {
  int n; vector<vector<int>> A;
  eulertour(int n) : n(n), A(n) {}
  void add_edge(int a, int b) {
    A[a].push_back(b); A[b].push_back(a);
  }
  vector<int> tour, enter, leave, V;
  void dfs(int v) {
    enter[v] = sz(tour);
    tour.push_back(v); 
    V[v] = 1;
    for (auto& a : A[v]) 
      if (!V[a])
        dfs(a);
    leave[v] = sz(tour);
    tour.push_back(v);
  }
  vector<int> get_tour(int root = 0) {
    enter.assign(n, 0); leave.assign(n, 0); V.assign(n, 0);
    dfs(root);
    return tour;
  }
};

const int cols = 100;
typedef __int128 int128;

int pc(int128 x) {
  int ans = 0;
  for (int i = 0; i < cols; i++)
    ans += (x >> i) & 1;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<int128> C(n);
  for (int i = 0, x = 0; i < n; i++) {
    cin >> x; x--; C[i] |= (int128(1) << x);
  }

  eulertour t(n);
  vector<vector<int>> A(n);
  for (int i = 1, p = 0; i < n; i++) {
    cin >> p; p--;
    t.add_edge(p, i);
    A[p].push_back(i);
  }

  vector<int> tour = t.get_tour(0);
  vector<int> enter = t.enter, leave = t.leave;
  vector<int128> X(2*n);
  for (int i = 0; i < n; i++) X[enter[i]] = C[i];
  segment<int128> st(2*n, 0, [] (int128 v, int128 u) { return v ^ u; }, X);

  for (int i = 0; i < q; i++) {
    int c, v; cin >> c >> v; c--; v--;
    if (c < 0) {
      int128 ans = st.query(enter[v], leave[v]);
      cout << pc(ans) << endl;
    } else {
      int128 x = (int128(1) << c);
      st.update(enter[v], x);
    }
  }
}

