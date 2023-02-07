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
  multiset<int> B;
  for (auto& a : A) cin >> a;
  for (int i = 0, x; i < n; i++) cin >> x, B.insert(x);

  vector<int> C(n);
  for (int i = 0; i < n; i++) {
    auto lb = B.lower_bound(n - A[i]);
    if (lb != end(B)) {
      C[i] = (A[i] + *lb) % n;
      B.erase(lb);
    } else {
      C[i] = (A[i] + *begin(B)) % n;
      B.erase(begin(B));
    }
  }

  for (auto& c : C) cout << c << ' ';
  cout << endl;
}

