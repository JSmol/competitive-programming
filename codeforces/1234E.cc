#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
ll n, m;
vector<ll> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(m, 0);
  for (auto& a : A) cin >> a;

  vector<ll> X(n+2);
  for (int i = 0; i < m-1; i++) {
    ll x = A[i];
    ll y = A[i+1];
    if (x == y) continue;
    if (x > y) swap(x, y);

    X[1] += abs(y - x);
    X[x] -= abs(y - x);

    X[x] += abs(y - 1);
    X[x+1] -= abs(y - 1);

    X[x+1] += abs(y - (x+1));
    X[y] -= abs(y - (x+1));

    X[y] += abs(x);
    X[y+1] -= abs(x);

    X[y+1] += abs(y - x);
    X[n+1] -= abs(y - x);
  }


  for (ll i = 1, s = 0; i <= n; i++) {
    s += X[i];
    cout << s << (i == n ? "\n" : " ");
  }
}

