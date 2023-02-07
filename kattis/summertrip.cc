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
string s;
int A[26][101010];
int B[26][101010];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  n = s.length();

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 26; j++)
      A[j][i] = n, B[j][i] = -1;

  for (int c = 0; c < 26; c++) {
    A[s[n-1] - 'a'][n-1] = n-1;
    for (int i = n-2; i >= 0; i--) {
      A[c][i] = (s[i] == 'a' + c ? i : A[c][i+1]);
    }

    B[s[0] - 'a'][0] = 0;
    for (int i = 1; i < n; i++) {
      B[c][i] = (s[i] == 'a' + c ? i : B[c][i-1]);
    }
  }

  // A[c][i] = idx of the next occur of c.
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (c + 'a' == s[i]) continue;
      int m = A[s[i] - 'a'][i+1];
      auto lb = lower_bound(B[c], B[c] + n, i);
      if (lb != B[c] + n and i < *lb and *lb < m) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}

