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

typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<ll> A(n);
  for (auto& a : A) cin >> a;

  sort(all(A));

  vector<ll> X(n);
  X[0] = A[0];
  for (ll i = 1; i < n; i++) X[i] = X[i-1] + A[i];

  vector<ll> ans(n);
  for (ll i = 0; i < m; i++) {
    for (ll j = i, s = 0; j < n; j += m) {
      s += (j-m >= 0 ? X[j-m] : 0);
      s += X[j] - (j-m >= 0 ? X[j-m] : 0);
      ans[j] = s;
    }
  }
  
  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

