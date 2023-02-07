#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int fexp(int x, int p) {
  int r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x);
    else p >>= 1, x = (x * x);
  }
  return r;
}

int f(vector<int> A) {
  int v = 0;
  rep(i, 0, 6) v += A[i]*fexp(7, i);
  return v;
}

map<int, int> M;
bool permute(vector<int> A, vector<int> p) {
  vector<int> r(6);
  rep(i, 0, 6) {
    r[i] = A[p[i]];
  }
  
  if (M.count(f(r))) {
    M[f(r)]++;
    return 1;
  } else {
    return 0;
  }
}

set<vector<int>> P = {
  {1,3,2,4,0,5},
  {2,1,3,5,4,0},
  {0,2,4,3,5,1}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  trav(p, P) {
    vector<int> n = p;
    rep(i, 0, 4) {
      rep(j, 0, 6) {
        n[j] = p[n[j]];
      }
      P.insert(n);
    }
  }

  trav(p, P) {
    trav(q, P) {
      vector<int> n(6, 0);
      rep(i, 0, 6) {
        n[i] = p[q[i]];
      }
      P.insert(n);
    }
  }

  rep(i, 0, n) {
    vector<int> A(6);
    trav(a, A) cin >> a;
    vector<int> X(6);
    X[0] = A[2];
    X[1] = A[0];
    X[2] = A[5];
    X[3] = A[3];
    X[4] = A[1];
    X[5] = A[4];
    A = X;


    bool flag = 0;
    trav(p, P) {
      if (permute(A, p)) {
        flag = 1;
        break;
      }
    }
    if (!flag) M[f(A)] = 1;
  }

  int ans = 0;
  trav(m, M) {
    if (m.snd > ans) {
      ans = m.snd;
    }
  }

  debug(P);
  debug(M);
  cout << ans << endl;
}

