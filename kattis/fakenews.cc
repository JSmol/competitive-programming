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

typedef long long ll;
template<typename T>
T bpow(T x, ll n) { return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1); }

map<string, int> M = {
  {"truther", 0},
  {"fabulist", 1},
  {"charlatan", 2}
};

map<int, string> N = {
  {0, "truther"},
  {1, "fabulist"},
  {2, "charlatan"}
};

int f(const vector<int>& role, stringstream& ss) {
  string op; ss >> op;
  if (M.count(op)) {
    int x; ss >> x;
    return role[x-1] == M[op];
  } else {
    if (op == "not") {
      return !f(role, ss);
    }
    if (op == "and") {
      int p = f(role, ss);
      int q = f(role, ss);
      return p & q;
    }
    if (op == "xor") {
      int p = f(role, ss);
      int q = f(role, ss);
      return p ^ q;
    }
  }

  assert(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  cin.ignore();

  vector<string> A(k);
  for (int i = 0; i < k; i++) {
    getline(cin, A[i]);
  }

  for (int b = 0; b < bpow(3, n); b++) {

    vector<int> role(n);
    for (int i = 0; i < n; i++) {
      role[i] = (b / bpow(3, i)) % 3;
    }

    int p = 1;
    vector<vector<int>> S(n);
    for (auto& s : A) {
      stringstream ss(s);
      int x; ss >> x;
      int res = f(role, ss);

      if (role[x-1] == 0 and !res) {
        p = 0;
        goto nxt;
      }

      if (role[x-1] == 1 and res) {
        p = 0;
        goto nxt;
      }

      S[x-1].push_back(res);
      
    }

    for (int i = 0; i < n; i++) {
      if (role[i] == 0) {
        p &= accumulate(all(S[i]), 0) == sz(S[i]);
      }
      if (role[i] == 1) {
        p &= accumulate(all(S[i]), 0) == 0;
      }
      if (role[i] == 2) {
        int j = 0;
        while (j < sz(S[i]) and S[i][j]) j++;
        p &= j > 0;
        p &= j < sz(S[i]);
        p &= accumulate(begin(S[i]) + j, end(S[i]), 0) == 0;
      }
    }

nxt:;
    if (p) {
      for (int i = 0; i < n; i++) {
        cout << N[role[i]] << endl;       
      }

      return 0;
    }
  }
}
