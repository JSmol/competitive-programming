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

int n, q;
int A[101010], B[101010], X[101010], Y[101010];

int f(int i, int j) {
  return X[j] - (i ? X[i-1] : 0);
}

int g(int i, int j) {
  return Y[j] - (i ? Y[i-1] : 0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 0, x; i < n; i++) cin >> x, A[i] = x & 1;
  for (int i = 0, x; i < n; i++) cin >> x, B[i] = x & 1;
  for (int i = 0; i < n; i++) {
    X[i] = (i ? X[i-1] : 0) + A[i];
    Y[i] = (i ? Y[i-1] : 0) + B[i];
  }

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d; a--; b--; c--; d--;
    int x1 = min(a, c);
    int x2 = max(a, c);
    int y1 = min(b, d);
    int y2 = max(b, d);
    if ((f(x1, x2) == 0 or f(x1, x2) == x2 - x1 + 1) and (g(y1, y2) == 0 or g(y1, y2) == y2 - y1 + 1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;   
    }
  }
}

