#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  vector<vector<string>> A(n);
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      string p;
      cin >> p;
      A[i].push_back(p);
    }
  }

  int m;
  cin >> m;
  vector<string> G(m);
  for (auto& s : G) cin >> s;

  int g = 0;
  set<string> S;
  vector<int> I(n, 0);
  vector<vector<string>> ans(n);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      while(I[j] < A[j].size() and S.count(A[j][I[j]])) I[j]++;
      if (I[j] < A[j].size()) {
        ans[j].push_back(A[j][I[j]]);
        S.insert(A[j][I[j]]);
      } else {
        while (g < G.size() and S.count(G[g])) g++;
        ans[j].push_back(G[g]);
        S.insert(G[g]);
      }
    }
  }

  for (auto& t : ans) {
    for (auto& p : t) cout << p << ' ';
    cout << endl;
  }
}

