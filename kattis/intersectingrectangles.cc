#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n;
vector<pair<pair<int, int>, pair<int, int>>> A;
vector<pair<int, pair<int, int>>> X;
set<int> H;

bool f() {
  for (auto& x : X) {
    int i = x.snd.fst;

    if (x.snd.snd == 1) {
      H.erase(A[i].fst.snd);
      H.erase(A[i].snd.snd);
    }

    if (!H.empty()) {
      auto h = H.lower_bound(A[i].fst.snd);
      if (h != H.end() and A[i].fst.snd < *h and *h < A[i].snd.snd)
        return 1;
    }

    if (x.snd.snd == 0) {
      H.insert(A[i].fst.snd);
      H.insert(A[i].snd.snd);
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, {});
  for (int i = 0; i < n; i++) {
    cin >> A[i].fst.fst >> A[i].fst.snd >> A[i].snd.fst >> A[i].snd.snd;
    X.push_back({A[i].fst.fst, {i, 0}});
    X.push_back({A[i].snd.fst, {i, 1}});
  }

  sort(ALL(X));
  cout << f() << endl;
}

