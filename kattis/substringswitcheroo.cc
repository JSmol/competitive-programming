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
 
int n;
string a, b;

typedef long long ll;
const ll p1 = 1e9+21;
const ll p2 = 1e9+9;

ll fexp(ll x, ll p, ll mod) {
  ll r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  return r;
}

pair<ll, ll> vhash(vector<int>& x) {
  ll v = 0;
  rep(i, 0, sz(x)) v = (v + (x[i]+1) * fexp(n+2, i, p1)) % p1;
  ll w = 0;
  rep(i, 0, sz(x)) w = (w + (x[i]+1) * fexp(n+2, i, p2)) % p2;
  return {v, w};
}

int c(char x) { return x - 'a'; }
int f(int l) {
  if (l > n) return 0;
  vector<vector<int>> B(n, vector<int>(26, 0));
  vector<vector<int>> A(n, vector<int>(26, 0));

  int j = 0;
  while (j < l) {
    A[0][c(a[j])]++;
    B[0][c(b[j])]++;
    j++;
  }

  set<pair<ll, ll>> S;
  S.insert(vhash(B[0]));
  for (int i = 1; j < n; i++, j++) {
    A[i] = A[i-1];
    A[i][c(a[i-1])]--;
    A[i][c(a[j])]++;
    B[i] = B[i-1];
    B[i][c(b[i-1])]--;
    B[i][c(b[j])]++;
    S.insert(vhash(B[i]));
  }

  // debug(S);
  // rep(i,0,n) debug(A[i]);
  // rep(i,0,n) debug(B[i]);

  rep(i, 0, n-l+1) {
    if (S.count(vhash(A[i]))) {
      cout << a.substr(i, l) << endl;
      return 1;
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    n = sz(a);
    bool p = 0;
    for (int i = n; i > 0; i--) {
      if (f(i)) {
        p = true;
        break;
      }
    }

    if (!p) cout << "NONE" << endl;
  }
}

