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
ll A[1111][1111], ans[1111];
ll n;

bool check(int a) {
  ans[0] = a;
  for (int i = 1; i < n; i++) {
    ans[i] = A[i][0] / ans[0];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (ans[i] * ans[j] != A[i][j])
          return false;
      }
    }
  }

  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }

  ll g = 0;
  for (int i = 0; i < n; i++) {
    g = __gcd(g, A[i][0]);
  }

  set<ll> S;
  for (int i = 1; i*i <= g; i++) {
    if (g % i == 0) {
      S.insert(i);
      S.insert(g/i);
    }
  }

  for (auto& s : S) {
    if (check(s)) {
      break;
    }
  }
}

