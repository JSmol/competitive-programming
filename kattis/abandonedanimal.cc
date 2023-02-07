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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<set<string>> A(n);
  for (int i = 0; i < k; i++) {
    int a;
    string s;
    cin >> a >> s;
    A[a].insert(s);
  }

  int m;
  cin >> m;
  vector<string> S(m);
  for (auto& s : S) cin >> s;

  vector<int> x; vector<int> y;
  for (int i = 0, a = 0, b = 0; i < n; i++) {
    while (a < m and A[i].count(S[a])) x.push_back(i), a++;
    while (b < m and A[n-1-i].count(S[m-1-b])) y.push_back(n-1-i), b++;
  }

  reverse(all(y));
  if (x.size() < m) cout << "impossible" << endl;
  else if (x == y) cout << "unique" << endl;
  else if (x != y) cout << "ambiguous" << endl;
}

