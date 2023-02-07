#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define ALL(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

int n, q, m;
vector<pair<int, int>> A;
int s[5050], t[5050];
int C[5050], D[5050], E[5050];

int f(pair<int, int>& a, pair<int, int>& b) {
  int x = 0;

  if (a.fst == b.fst and a.snd < b.snd)
    swap(a, b);

  if (a.snd >= b.fst) {
    if (a.snd >= b.snd) {
      x += C[b.fst-1] - C[a.fst-1];
      x += D[b.snd] - D[b.fst-1];
      x += C[a.snd] - C[b.snd];
    } else {
      x += C[b.fst-1] - C[a.fst-1];
      x += D[a.snd] - D[b.fst-1];
      x += C[b.snd] - C[a.snd];
    }
  } else {
    x += C[a.snd] - C[a.fst-1];
    x += C[b.snd] - C[b.fst-1];
  }

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  A.assign(q, {});
  for (int i = 0; i < q; i++) cin >> A[i].fst >> A[i].snd, s[A[i].fst]++, t[A[i].snd]++;

  for (int i = 1, c = 0, d = 0, e = 0; i <= n; i++) {
    e += s[i];
    if (e > 0) m++;

    E[i] = e;
    c += (e == 1);
    C[i] = c;
    d += (e == 2);
    D[i] = d;
    e -= t[i];
  }

  int ans = 0;
  for (int i = 0; i < q; i++) {
    for (int j = i+1; j < q; j++) {
      if (A[i].fst <= A[j].fst)
        ans = max(ans, m - f(A[i], A[j]));
      else
        ans = max(ans, m - f(A[j], A[i]));
    }
  }
  cout << ans << endl;
}

