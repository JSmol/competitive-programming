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

int bs (const vector<int>& A, const vector<int>& L, int h, int v) {
  int l = 0;
  while ((h - l) > 5) {
    int m = (h + l) / 2;
    (A[L[m]] >= v ? h : l) = m;
  }

  while (A[L[l]] < v)
    l++;

  return l;
}

int lis(vector<int> A, int n) {
  if (n == 0) return 0;

  vector<int> L(n, 0);
  vector<int> P(n, -1);
  int e = 0;

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

  return e + 1;
}

int n;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int& a = A[i];
    vector<int> b, s;
    for (int j = i+1; j < n; j++) {
      int& x = A[j];
      if (a < x) b.push_back(x-a);
      else s.push_back(a-x);
    }

    ans = max(ans, 1 + lis(b, b.size()) + lis(s, s.size()));
  }
  cout << ans << endl;
}

