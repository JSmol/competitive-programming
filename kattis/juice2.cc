#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int t, n;
vector<tuple<int, int, int>> A;
vector<pair<int, int>> B;

int f(int m, int c) {
  c = 10000 - c;
  for (int i = 0; i < m; i++)
    B[i].fst = get(A[i], 1), B[i].snd = get(A[i], 2);

  sort(begin(B), begin(B)+m);

  priority_queue<int> Q;
  int p = B[0].fst;
  int b = 0, i = 0;
  while (c - p >= 0) {
    while (i < m and B[i].fst == p)
      Q.push(B[i].snd),
      i++;

    while (!Q.empty() and Q.top() > c - p)
      Q.pop();

    b = max(b, (int) Q.size());
    if (i < m)
      p = B[i].fst;
    else
      break;
  }

  return b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  int c = 0;
  while (t--) {
    c++;
    cin >> n;
    A.assign(n, {});
    B.assign(n, {});

    for (int i = 0; i < n; i++)
      cin >> get(A[i], 0) >> get(A[i], 1) >> get(A[i], 2);

    sort(begin(A), end(A));
    int p = get(A[0], 0);
    int m = 0, i = 0;
    while (true) {
      while (i < n and get(A[i], 0) == p)
        i++;

      m = max(m, f(i, p));
      if (i < n)
        p = get(A[i], 0);
      else 
        break;
    }

    cout << "Case #" << c << ": " << m << endl;
  }
}

