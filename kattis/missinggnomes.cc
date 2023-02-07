#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<int> T;
  vector<int> A(m);
  for (auto& a : A) cin >> a, T.insert(a);

  set<int> S;
  for (int i = 1; i <= n; i++) if (!T.count(i)) S.insert(i);

  for (int i = 0, j = 0; i < n; i++) {
    if (!S.empty() and j < m and *begin(S) < A[j]) {
      cout << *begin(S) << '\n';
      S.erase(begin(S));
    } else 
    if (!S.empty() and j < m and *begin(S) > A[j]) {
      cout << A[j] << '\n';
      j++;
    } else 
    if (!S.empty()) {
      cout << *begin(S) << '\n';
      S.erase(begin(S));
    } else {
      cout << A[j] << '\n';
      j++;
    }
  }
}

