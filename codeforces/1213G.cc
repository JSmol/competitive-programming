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

typedef long long ll;
ll f(ll x) {
  return (x * (x-1)) / 2;
}

struct UF {
  int n; ll ans; vector<int> A; vector<ll> S;
  UF (int n) : n(n), ans(0), A(n), S(n, 1) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { 
    assert(!connected(a, b));
    ans -= f(S[find(a)]);
    ans -= f(S[find(b)]);
    ll s = S[find(a)] + S[find(b)];
    ans += f(s);
    A[find(b)] = find(a); 
    S[find(a)] = s;
    assert(S[find(b)] == s);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> A(n-1);
  for (auto& a : A) {
    cin >> a.snd.fst >> a.snd.snd >> a.fst;
    a.snd.fst--;
    a.snd.snd--;
  }

  sort(all(A));
  vector<pair<int, int>> Q(m);
  for (int i = 0; i < m; i++) {
    cin >> Q[i].fst;
    Q[i].snd = i;
  }

  sort(all(Q));
  vector<ll> ans(m);

  UF uf(n);
  for (int i = 0, j = 0; i < m; i++) {
    while (j < n-1 and A[j].fst <= Q[i].fst) {
      uf.merge(A[j].snd.fst, A[j].snd.snd);
      j++;
    }

    ans[Q[i].snd] = uf.ans;
  }

  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

