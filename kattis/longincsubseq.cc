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


int bs (const vector<int>& A, const vector<int>& L, int h, int v) {
  int l = 0;
  while ((h - l) > 0) {
    int m = (h + l) / 2;
    if (A[L[m]] >= v) h = m;
    else l = m+1;
  }

  return l;
}

vector<int> lis(vector<int>& A, int n) {
  int e = 0;
  vector<int> L(n, 0);
  vector<int> P(n, -1);

  for (int i = 1; i < n; i++) {
    if (A[i] <= A[L[0]]) {
      L[0] = i;
    } else if (A[i] > A[L[e]]) {
      P[i] = L[e];
      e++;
      L[e] = i;
    } else {
      int j = bs(A, L, e, A[i]);
      P[i] = L[j-1];
      L[j] = i;
    }
  }

  vector<int> s(e+1);
  int k = L[e];
  while (k != -1) {
    s[e] = k;
    k = P[k];
    e--;
  }

  return s;
}

int main () {
  int n;
  while (cin >> n) {
    vector<int> A(n);
    for (auto& a : A) cin >> a;
    vector<int> ans = lis(A, n);
    cout << ans.size() << endl;
    for (auto& a : ans) cout << a << ' ';
    cout << endl;
  }
}

