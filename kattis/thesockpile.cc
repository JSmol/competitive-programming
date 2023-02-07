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

int P, W;
int V[505][505][202];
double dp[505][505][202];

double f(int p, int q, int w) {
  double& x = dp[p][q][w];
  if (V[p][q][w]) return x;
  V[p][q][w] = 1;
  
  if (p == 0 and w <= 1) return x = 1;

  double n = 2*p + q + w;
  if (q >= 2) x += f(p, q-2, w) * ((q/n) * ((q-1)/(n-1)));
  if (p >= 2) x += f(p-2, q+2, w) * ((2.0*p/n) * ((2.0*(p-1))/(n-1)));
  if (p >= 1 and q >= 1) x += f(p-1, q, w) * ((2.0*p/n) * (q/(n-1)) + (q/n) * (2.0*p/(n-1)));
  if (w >= 1 and q >= 1) x += f(p, q-1, w-1) * ((w/n) * (q/(n-1)) + (q/n) * (w/(n-1)));
  if (w >= 1 and p >= 1) x += f(p-1, q+1, w-1) * ((w/n) * (2.0*p/(n-1)) + (2.0*p/n) * (w/(n-1)));

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> P >> W;
  cout << fixed << setprecision(9) << f(P, 0, W) << endl;
}

