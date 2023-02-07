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

struct fenwick {
  vector<int> A; int n;
  fenwick(vector<int>& x, int s) { n = s+1; A.assign(n, 0); for (int i = 0; i < n; i++) add(i+1, x[i]); }
  void add(int i, int v) { while (i < n) A[i] += v, i += i & -i; } 
  int query(int i) { int s = 0; while (i > 0) s += A[i], i -= i & -i; return s; }
};

const int maxn = 1e6+5;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a;

  int ans = 1;
  set<int> Z;
  vector<int> S;
  vector<int> X(maxn);
  fenwick t(X, maxn-1);
  for (int i = 0, c = 0; i < n; i++) {
    if (A[i] < 0) {
      int x = (-1) * A[i];
      if (X[x] == 0) {
        ans = 0;
        break;
      } else {
        X[x] = 0;
        t.add(x, -1);
      }
    } else {
      int x = A[i];
      if (X[x] == 1) {
        ans = 0;
        break;
      } else {
        if (Z.count(x)) {
          ans = 0;
          break;
        }

        Z.insert(x);
        X[x] = 1;
        t.add(x, 1);
      }
    }

    c++;
    if (t.query(maxn-1) == 0) {
      S.push_back(c);
      Z.clear();
      c = 0;
    }
  }
  
  if (ans == 0 or t.query(maxn-1) != 0) {
    cout << -1 << endl;;
  } else {
    cout << sz(S) << endl;
    for (auto& s : S) cout << s << ' ';
    cout << endl;
  }
}

