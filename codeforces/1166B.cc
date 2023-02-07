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

int k, i, x, y;
string s;
string a = "aeiou";

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> k;

  for (i = 5; i * i <= k; i++) {
    if (k % i == 0) {
      for (x = 0; x < i; x++) {
        for (y = 0; y < k/i; y++) {
          cout << a[(x+y) % 5];
        }
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

