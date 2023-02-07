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

#define double long double
double eps = 1e-9;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<double> A(4);
  for (int i = 0; i < 4; i++) {
    cin >> A[i];
  }

  double t;
  cin >> t;

  sort(all(A));

  if (3*t - (A[1] + A[2] + A[3]) > -eps) {
    cout << "infinite" << endl;
    return 0;
  }

  if (3*t - (A[0] + A[1] + A[2]) < -eps) {
    cout << "impossible" << endl;
    return 0;
  }

  double g = 3 * t - (A[1] + A[2]);
  // assert(g >= A[0]);
  // assert(g <= A[3]);
  cout << setprecision(2) << fixed << g << endl;
}

