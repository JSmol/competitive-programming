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

int n, k;
string s;
int C[1<<20][20];
int dp[1<<20];
vector<int> N;
set<char> S;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k >> s;

  for (auto& c : s) S.insert(c);

  int x = 0;
  N.assign(300, -1);
  for (auto& c : S) N[c] = x, x++;

  for (int b = (1 << k)-2; b >= 0; b--) {
    for (int i = 0, j = 0; i < n; i = j) {
      j = i+1;
      if (b & (1 << N[s[i]])) continue;
      while ((j < n and s[i] == s[j]) or (j < n and b & (1 << N[s[j]]))) j++;
      C[b][N[s[i]]]++;
    }

    dp[b] = 1 << 30;
    for (int i = 0; i < k; i++) {
      if (b & 1 << i) continue;
      dp[b] = min(dp[b], dp[b | (1 << i)] + C[b][i]);
    }
  }

  cout << dp[0] << endl;
}

