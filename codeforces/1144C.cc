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

int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a;
  sort(all(A));
  
  vector<int> x,y;
  x.push_back(A[0]);
  for (int i = 1; i < n; i++) {
    if (!y.empty() and A[i] == A[i-1] and A[i] == y.back()) {
      cout << "NO" << endl;
      return 0;
    }

    if (A[i] == A[i-1]) y.push_back(A[i]);
    else x.push_back(A[i]);
  }

  cout << "YES" << endl;
  cout << x.size() << endl;
  for (auto& a : x) cout << a << ' ';
  cout << endl;
  reverse(all(y));
  cout << y.size() << endl;
  for (auto& a : y) cout << a << ' ';
  cout << endl;
}

