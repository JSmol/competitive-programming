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
int c[202020];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> A(n);
  for (auto& a : A) cin >> a, c[a]++;
  int x = 0;
  for (int i = 0; i < 202020; i++) {
    if (c[i] > c[x]) x = i;
  }

  cout << n - c[x] << endl;
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    if (x == A[i]) Q.push(i);
  }

  while (!Q.empty()) {
    int i = Q.front();
    Q.pop();

    if (i > 0 and A[i-1] != x) {
      if (A[i-1] < x) cout << 1 << ' ' << i << ' ' << i+1 << endl;
      else cout << 2 << ' ' << i << ' ' << i+1 << endl;
      A[i-1] = x;
      Q.push(i-1);
    }

    if (i < n-1 and A[i+1] != x) {
      if (A[i+1] < x) cout << 1 << ' ' << i+2 << ' ' << i+1 << endl;
      else cout << 2 << ' ' << i+2 << ' ' << i+1 << endl;
      A[i+1] = x;
      Q.push(i+1);
    }
  }
}

