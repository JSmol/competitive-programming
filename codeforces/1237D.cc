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

struct segment {
  const int id = -(1 << 30);
  int op(int a, int b) {
    return max(a, b);
  }

  int n;
  vector<int> S;
  segment(vector<int> A, int n) : n(n) {
    S.assign(2*n, id);
    for (int i = 0; i < n; i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  // query range A[l], ... , A[r-1].
  int query(int l, int r) {
    int ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> A(2*n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[n+i] = A[i];
  }

  segment st(A, 2*n);
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    if (2*A[i] >= st.query(0, 2*n)) continue;

    int l = 0; int h = n+i-1;
    while (h - l > 4) {
      int m = (h+l) / 2;
      if (2*A[i] < st.query(m, n+i)) l = m;
      else h = m-1;
    }

    while (l < n+i and 2*A[i] < st.query(l, n+i)) l++;
    if (ans[(l-1)%n] == -1) ans[(l-1)%n] = (n+i) - (l-1);
    else ans[(l-1)%n] = min(ans[(l-1)%n], (n+i) - (l-1));
  }

  for (int i = 2*n-1; i >= 0; i--) {
    if (ans[i%n] == -1) {
      if (ans[(i+1)%n] != -1) ans[i%n] = ans[(i+1)%n] + 1;
    } else {
      if (ans[(i+1)%n] != -1) ans[i%n] = min(ans[i%n], ans[(i+1)%n] + 1);
    }
  }

  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

