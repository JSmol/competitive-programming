#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll X[40];
  X[0] = 1;
  for (int i = 1; i < 40; i++)
    X[i] = X[i-1] * 3;

  int q;
  cin >> q;
  while (q--) {
    ll n;
    cin >> n;
    vector<ll> A(40);
    for (int i = 1; i < 40; i++) {
      A[i-1] = (n % X[i]) / X[i-1];
    }

    for (int i = 38, p = 0; i >= 0; i--) {
      if (A[i] == 2 and !p) {
        int j = i+1;
        while (j < 40 and A[j] == 1) j++;
        A[j] = 1;
        i = j;
        p = 1;
      } else
      if (p) A[i] = 0;
    }

    ll ans = 0;
    for (int i = 0; i < 40; i++) ans += A[i]*X[i];

    cout << ans << endl;
  }
}

