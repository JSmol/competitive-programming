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
int A[200000][27];
string s, t;

int c(char a) {
  return a - 'a';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s;

  vector<int> I(27, 0);
  for (int i = 0; i < n; i++) {
    I[c(s[i])]++;
    A[I[c(s[i])]][c(s[i])] = i;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t;
    vector<int> x(27, 0);
    for (auto& l : t) {
      x[c(l)]++;
    }

    int ans = 0;
    for (int j = 0; j < 27; j++) {
      if (x[j] > 0) {
        ans = max(ans, A[x[j]][j] + 1);
      }
    }
    cout << ans << endl;
  }
}

