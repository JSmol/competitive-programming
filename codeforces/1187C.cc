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

int n, m;
vector<pair<int, int>> A, B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0, t, a, b; i < m; i++) {
    cin >> t >> a >> b; a--; b--;
    if (t) A.push_back({a, b});
    else B.push_back({a, b});
  }

  sort(all(A));
  sort(all(B));

  vector<int> ans(n);
  priority_queue<int, vector<int>, greater<int>> AQ, BQ;
  for (int i = 0, j = 0, k = 0, x = n; i < n; i++) {
    if (AQ.empty() and !BQ.empty()) {
      x--;
      ans[i] = x;
      while (!BQ.empty()) BQ.pop();
    } else {
      ans[i] = x;
    }

    while (j < A.size() and A[j].fst == i) {
      AQ.push(A[j].snd);
      j++;
    }

    while (!AQ.empty() and AQ.top() == i) AQ.pop();

    while (k < B.size() and B[k].fst == i) {
      BQ.push(B[k].snd);
      k++;
    }

    if (!BQ.empty() and BQ.top() == i) {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

