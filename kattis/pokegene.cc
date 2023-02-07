#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int s = 26;
const int MAXNODES = 202020;
int index(char c) { return (int) alphabet.find(c); }

struct trie {

  int n; vector<vector<int>> A;
  trie() : n(1), A(MAXNODES, vector<int>(s+1, 0)) { }

  // returns vertex of last char in w
  int add(string w, int v) {
    int i = 0, j = 0;
    int l = sz(w);
    while (j < l) {
      int& k = A[i][index(w[j])];
      if (k != 0) i = k, j++;
      else i = k = n++, j++;
    }
    A[i][s] = v;
    return i;
  }

  // returns value of w if it exists
  int find(string w) {
    int i = 0;
    for (auto& l : w){
      int c = index(l);
      i = A[i][c];
      if (!i) return -1;
    }
    return A[i][s];
  }

  // D[i] = depth of node i
  vector<int> D;
  void dfs(int v, int d) {
    D[v] = d;
    for (int i = 0; i < s; i++) {
      if (A[v][i]) dfs(A[v][i], d+1);
    }
  }

  // P[i][j] = the node that is 2^j levels above i
  vector<vector<int>> P;
  void initlca() {
    D.assign(n, -1); dfs(0, 0);
    P.assign(n, vector<int>(22, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < s; j++)
        if (A[i][j]) P[A[i][j]][0] = i;
    for (int i = 0; i < n; i++)
      for (int j = 1; j < 22; j++)
        P[i][j] = P[P[i][j-1]][j-1];
  }

  int lca(int a, int b) {
    if (D[b] > D[a]) swap(a, b);
    for (int j = 21; D[a] > D[b]; j--)
      while (D[P[a][j]] >= D[b]) a = P[a][j];
    assert(D[a] == D[b]);
    if (a == b) return a;
    for (int j = 21; j >= 0; j--)
      if (P[a][j] != P[b][j])
        a = P[a][j], b = P[b][j];
    // lca doesnt exist ?
    assert(P[a][0] == P[b][0]);
    return P[a][0];
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;

  trie T;
  vector<pair<string, int>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].fst;
    A[i].snd = T.add(A[i].fst, i+1);
  }

  T.initlca();
  while (q--) {
    int k, l;
    cin >> k >> l;
    vector<pair<string, int>> Q(k);
    for (int i = 0, x; i < k; i++) {
      cin >> x;
      Q[i] = A[x-1];
    }

    sort(all(Q));
    int ans = 0;
    for (int i = 0, j = l-1; j < k; i++, j++) {
      int a = T.lca(Q[i].snd, Q[j].snd);
      ans += T.D[a];
      if (i-1 >= 0 and j+1 < k) {
        int b = T.lca(Q[i-1].snd, Q[j].snd);
        int c = T.lca(Q[i].snd, Q[j+1].snd);
        ans -= max(T.D[b], T.D[c]);
      } else if (i-1 >= 0) {
        int b = T.lca(Q[i-1].snd, Q[j].snd);
        ans -= T.D[b];
      } else if (j+1 < k) {
        int c = T.lca(Q[i].snd, Q[j+1].snd);
        ans -= T.D[c];
      }
    }
    cout << ans << endl;
  }
}


